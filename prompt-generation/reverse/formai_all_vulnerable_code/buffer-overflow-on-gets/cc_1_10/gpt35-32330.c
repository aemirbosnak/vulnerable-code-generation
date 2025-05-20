//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_WATERMARK_LENGTH 20

void embedWatermark(char message[], char watermark[])
{
    int messageLength = strlen(message);
    int watermarkLength = strlen(watermark);
    int i = 0, j = 0;
    int watermarkIndex = 0;

    for(i = 0; i < messageLength; i++)
    {
        if(j == watermarkLength)
        {
            j = 0;
        }

        watermarkIndex = (int)watermark[j];

        message[i] = message[i] | (watermarkIndex << 8);

        j++;
    }
}

void extractWatermark(char message[], char watermark[])
{
    int messageLength = strlen(message);
    int watermarkLength = strlen(watermark);
    int i = 0, j = 0;
    int watermarkIndex = 0;

    for(i = 0; i < messageLength; i++)
    {
        if(j == watermarkLength)
        {
            j = 0;
        }

        watermarkIndex = (int)watermark[j];

        watermark[j] = (message[i] & 0xFF00) >> 8;

        j++;
    }
}

int main()
{
    char message[MAX_MESSAGE_LENGTH];
    char watermark[MAX_WATERMARK_LENGTH];
    char extractedWatermark[MAX_WATERMARK_LENGTH];
    int choice = 0;

    printf("Enter message to be watermarked (max length %d): ", MAX_MESSAGE_LENGTH);
    gets(message);

    printf("Enter watermark (max length %d): ", MAX_WATERMARK_LENGTH);
    gets(watermark);

    do
    {
        printf("\nChoose an operation:\n");
        printf("1. Embed watermark\n");
        printf("2. Extract watermark\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        fflush(stdin);

        switch(choice)
        {
            case 1:
                embedWatermark(message, watermark);
                printf("Watermark embedded successfully.\n");
                break;
            case 2:
                extractWatermark(message, extractedWatermark);
                printf("Extracted watermark: %s\n", extractedWatermark);
                break;
            case 3:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 3);

    return 0;
}