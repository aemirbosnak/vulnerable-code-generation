//MISTRAL-7B DATASET v1.0 Category: QR code generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#define QR_SIZE 256
#define BLOCK_SIZE 16
#define MASK 0x21010101

typedef struct qr_data {
    uint8_t version;
    uint8_t id;
    uint8_t ec_level;
    uint16_t total_bytes;
    uint16_t data_length;
    uint16_t addr_length;
    uint8_t byte_len;
    uint8_t byte_pos;
    uint8_t interleaver[BLOCK_SIZE];
    char data[QR_SIZE];
} qr_data_t;

void interleave(qr_data_t* data) {
    int i, j, k, pos;
    for (i = 0; i < data->total_bytes; i++) {
        pos = data->byte_pos++;
        j = (i * 8) / data->byte_len;
        k = (i * 8) % data->byte_len;
        data->interleaver[pos] = (data->data[j] >> k) & 1;
    }
}

void qr_code_gen(const char* str, char* buf) {
    qr_data_t data;
    int i, j, len;

    memset(&data, 0, sizeof(qr_data_t));
    data.version = 0x01;
    data.id = 0x00;
    data.ec_level = 0x02;
    data.total_bytes = 196;

    len = strlen(str);
    if (len > 208) {
        fprintf(stderr, "String too long.\n");
        exit(EXIT_FAILURE);
    }

    data.data_length = len + 4;
    data.addr_length = (data.data_length + 1) >> 3;

    strncpy(data.data, str, len + 1);

    for (i = 0; i < len + 4; i++) {
        if (i < len) {
            data.data[i + 4] = data.data[i];
        } else {
            data.data[i + 4] = 0xEC;
        }
    }

    interleave(&data);

    for (i = 0; i < QR_SIZE; i++) {
        buf[i] = MASK & data.interleaver[i];
    }
}

int main() {
    char str[256], qr_code[QR_SIZE];
    int fd, ret;

    printf("Enter the string to generate QR code: ");
    scanf("%s", str);

    qr_code_gen(str, qr_code);

    fd = open("qr_code.bin", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    ret = write(fd, qr_code, QR_SIZE);
    if (ret < 0) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    close(fd);

    printf("QR code generated successfully.\n");

    return EXIT_SUCCESS;
}