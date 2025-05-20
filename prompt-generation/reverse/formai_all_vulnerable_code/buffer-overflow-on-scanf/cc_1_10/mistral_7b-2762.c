//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_NUM 32
#define MSG_LEN 100

typedef struct {
    uint32_t num[MAX_NUM];
    char msg[MSG_LEN];
} data_t;

void process_bits(uint32_t num) {
    int i, j;
    uint8_t bits[8];

    for (i = 0, j = 7; i < 8; i++, j--) {
        bits[i] = num >> j & 1;
    }

    for (i = 0; i < 8; i++) {
        printf("%d", bits[i]);
    }

    printf(" ");
}

int main() {
    data_t data;
    int i;

    printf("Enter %d numbers: ", MAX_NUM);

    for (i = 0; i < MAX_NUM; i++) {
        scanf("%d", &data.num[i]);
    }

    printf("\nEnter the message: ");
    fgets(data.msg, MSG_LEN, stdin);
    data.msg[strcspn(data.msg, "\n")] = '\0';

    printf("\nNumbers: ");

    for (i = 0; i < MAX_NUM; i++) {
        printf("%d ", data.num[i]);
        process_bits(data.num[i]);
    }

    printf("\nMessage: %s", data.msg);

    return 0;
}