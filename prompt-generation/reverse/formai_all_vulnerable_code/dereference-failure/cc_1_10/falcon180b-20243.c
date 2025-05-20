//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_QR_SIZE 4096

struct qr_data {
    uint8_t *data;
    size_t size;
};

static void *decode_qr(void *arg)
{
    struct qr_data *qr = arg;
    uint8_t *data = qr->data;
    size_t size = qr->size;

    uint8_t version;
    uint8_t error_correction_level;
    uint32_t mask_pattern;
    uint8_t *data_bits;
    size_t data_bits_size;

    if (size < 21) {
        printf("QR code too small\n");
        return NULL;
    }

    version = data[0] >> 4;
    error_correction_level = (data[0] & 0x0F) + 1;

    mask_pattern = 0;
    for (int i = 0; i < 8; i++) {
        mask_pattern |= (data[i + 1] >> (7 - i)) & 1;
    }

    data_bits_size = (size - 21) * 8;
    data_bits = malloc(data_bits_size);

    for (int i = 0; i < data_bits_size; i++) {
        int x = i / 8;
        int y = i % 8;
        int bit = (data[x + 1] >> (7 - y)) & 1;

        if (mask_pattern & (1 << y)) {
            bit ^= 1;
        }

        data_bits[i] = bit;
    }

    printf("Decoded QR code: %s\n", data_bits);

    free(data_bits);

    return NULL;
}

int main()
{
    pthread_t thread_id;
    struct qr_data qr_data;

    printf("Enter QR code data (max %d bytes):\n", MAX_QR_SIZE);
    fgets(qr_data.data, MAX_QR_SIZE, stdin);
    qr_data.size = strlen(qr_data.data);

    pthread_create(&thread_id, NULL, decode_qr, &qr_data);
    pthread_join(thread_id, NULL);

    return 0;
}