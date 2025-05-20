//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_WATERMARK_LENGTH 10
#define MAX_DATA_LENGTH 1000
#define ALPHA 0.5                /* Alpha value is used for visibility control */

/* Function to add a binary watermark to binary data */
void add_watermark(char *data, char *watermark) {
    int len, i, j;

    len = strlen(watermark);
    for (i = 0, j = 0; i < len; i++, j += 8) {
        /* Add each byte of watermark to 8 bits of data */
        data[j+7] = (watermark[i] & 0x01) | ((data[j+7] & 0xfe) & 0xff);
        data[j+6] = ((watermark[i] >> 1) & 0x01) | ((data[j+6] & 0xfe) & 0xff);
        data[j+5] = ((watermark[i] >> 2) & 0x01) | ((data[j+5] & 0xfe) & 0xff);
        data[j+4] = ((watermark[i] >> 3) & 0x01) | ((data[j+4] & 0xfe) & 0xff);
        data[j+3] = ((watermark[i] >> 4) & 0x01) | ((data[j+3] & 0xfe) & 0xff);
        data[j+2] = ((watermark[i] >> 5) & 0x01) | ((data[j+2] & 0xfe) & 0xff);
        data[j+1] = ((watermark[i] >> 6) & 0x01) | ((data[j+1] & 0xfe) & 0xff);
        data[j]   = ((watermark[i] >> 7) & 0x01) | ((data[j] & 0xfe) & 0xff);
    }
}

/* Function to extract watermark from binary data */
void extract_watermark(char *data, char *watermark) {
    int len, i, j;
    char byte;

    len = strlen(watermark);
    for (i = 0, j = 0; i < len; i++, j += 8) {
        /* Extract each byte of watermark from 8 bits of data */
        byte = (data[j+7] & 0x01) << 0 |
               (data[j+6] & 0x01) << 1 |
               (data[j+5] & 0x01) << 2 |
               (data[j+4] & 0x01) << 3 |
               (data[j+3] & 0x01) << 4 |
               (data[j+2] & 0x01) << 5 |
               (data[j+1] & 0x01) << 6 |
               (data[j]   & 0x01) << 7;
        watermark[i] = byte;
    }
    watermark[len] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH], watermark[MAX_WATERMARK_LENGTH], data[MAX_DATA_LENGTH];
    int choice, len, i;

    printf("Enter message to be watermarked: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    len = strlen(message);

    /* Convert message into binary data */
    for (i = 0; i < len; i++) {
        int j;
        for (j = 0; j < 8; j++) {
            data[i*8+j] = (message[i] >> (7-j)) & 0x01;
        }
    }

    /* Ask user for choice */
    printf("Choose an option:\n");
    printf("1. Add watermark.\n");
    printf("2. Extract watermark.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            /* Ask user for watermark */
            printf("Enter watermark: ");
            scanf("%s", watermark);

            /* Add watermark to binary data */
            add_watermark(data, watermark);

            /* Convert modified binary data into message */
            for (i = 0; i < len; i++) {
                int j, c = 0;
                for (j = 0; j < 8; j++) {
                    c += data[i*8+j] << (7-j);
                }
                message[i] = (char)c;
            }
            printf("Watermarked message: %s", message);
            break;

        case 2:
            /* Extract watermark from binary data */
            extract_watermark(data, watermark);
            printf("Extracted watermark: %s", watermark);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}