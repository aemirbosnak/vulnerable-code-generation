//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_MSG_LEN 100
#define MAX_WATERMARK_LEN 20

//Watermarking function that generates the watermark
char* generateWatermark(char *msg, int msgLen) {
    char *watermark = (char*)malloc(MAX_WATERMARK_LEN * sizeof(char));
    int i, j, k, l, watermarkLen = 0;

    for(i = 0; i < msgLen; i++) {
        watermarkLen += (int)pow(2, i);
    }

    int sum = 0;
    for(i = 0; i < msgLen; i++) {
        sum += (int)msg[i];
        watermark[i] = (char)(msg[i] + (sum % 26));
    }

    for(j = i, k = 0; j < watermarkLen; j++, k++) {
        watermark[j] = (char)(msg[k] + (sum % 26));
        sum += (int)watermark[j] - (int)msg[k];
    }

    watermark[j] = '\0';
    return watermark;
}

//Watermarking function that embeds the watermark in the digital data
void embedWatermark(char *data, int dataLen, char *watermark, int watermarkLen) {
    int i, j;

    for(i = 0; i < watermarkLen; i++) {
        for(j = 0; j < 8; j++) {
            if(i*8 + j >= dataLen) {
                return;
            }
            if(watermark[i] & (1 << (7 - j))) {
                data[i*8 + j] |= 1;
            }
            else {
                data[i*8 + j] &= 0xFE;
            }
        }
    }
}

//Watermarking function that extracts the watermark from the digital data
char* extractWatermark(char *data, int dataLen, int watermarkLen) {
    char *watermark = (char*)malloc(watermarkLen * sizeof(char));
    int i, j;

    for(i = 0; i < watermarkLen; i++) {
        watermark[i] = 0;
        for(j = 0; j < 8; j++) {
            if(i*8 + j >= dataLen) {
                return watermark;
            }
            if(data[i*8 + j] & 1) {
                watermark[i] |= (1 << (7 - j));
            }
        }
    }
    return watermark;
}

int main() {
    char msg[MAX_MSG_LEN], *watermark, *extractedWatermark;
    int msgLen, watermarkLen = 0;

    printf("Enter the message to be watermarked (Max length: %d): ", MAX_MSG_LEN);
    fgets(msg, MAX_MSG_LEN, stdin);
    msg[strcspn(msg, "\n")] = '\0'; //Remove trailing newline character

    msgLen = strlen(msg);
    printf("\nGenerating the watermark...\n");
    watermark = generateWatermark(msg, msgLen);
    watermarkLen = strlen(watermark);
    printf("\nThe generated watermark is: %s\nLength of the watermark: %d\n", watermark, watermarkLen);

    int dataLen = watermarkLen * 8;
    char data[dataLen];
    printf("\nEnter the digital data to embed the watermark (Length of the digital data should be at least %d): ", dataLen);
    fgets(data, MAX_MSG_LEN, stdin);
    data[strcspn(data, "\n")] = '\0'; //Remove trailing newline character

    embedWatermark(data, strlen(data), watermark, watermarkLen);
    printf("\nThe watermark has been embedded in the digital data successfully!\n");

    printf("\nEnter the digital data from which to extract the watermark (Length of the digital data should be at least %d): ", dataLen);
    char extractData[MAX_MSG_LEN];
    fgets(extractData, MAX_MSG_LEN, stdin);
    extractData[strcspn(extractData, "\n")] = '\0'; //Remove trailing newline character

    extractedWatermark = extractWatermark(extractData, strlen(extractData), watermarkLen);
    printf("\nThe extracted watermark is: %s\n", extractedWatermark);
    if(strcmp(watermark, extractedWatermark) == 0) {
        printf("\nThe watermark has been retrieved successfully and matches the original watermark!\n");
    }
    else {
        printf("\nThe watermark has NOT been retrieved successfully! Please check the digital data and try again.\n");
    }

    free(watermark);
    free(extractedWatermark);
    return 0;
}