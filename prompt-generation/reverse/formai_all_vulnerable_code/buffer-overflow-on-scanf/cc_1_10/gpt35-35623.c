//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define QR_CODE_SIZE 21
#define MAX_FILE_SIZE 2097

bool check_valid_qr_code(char qr_code[]);
void decode_qr_code(char qr_code[], char result[]);
void log_qr_code(char qr_code[]);

int main()
{
    char qr_code[QR_CODE_SIZE];
    char result[QR_CODE_SIZE];
    char log_file[MAX_FILE_SIZE];
    FILE *fptr;
    int count = 0;

    // Read QR codes until user chooses to stop
    while (true)
    {
        printf("Please scan a QR code: ");
        scanf("%s", qr_code);

        if (check_valid_qr_code(qr_code))
        {
            decode_qr_code(qr_code, result);
            printf("QR code successfully decoded: %s\n", result);
            log_qr_code(qr_code);
            count++;
        }
        else
        {
            printf("Invalid QR code. Please try again.\n");
        }

        char choice;
        printf("Do you want to scan another QR code? (Y/N) ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n')
        {
            break;
        }
    }

    // Log QR code count and timestamp to file
    time_t current_time;
    char timestamp[50];
    time(&current_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    fptr = fopen("log.txt", "a");
    if (fptr == NULL)
    {
        printf("Error: Could not open log file.\n");
    }
    else
    {
        fprintf(fptr, "QR codes scanned: %d\tTimestamp: %s\n", count, timestamp);
        fclose(fptr);
        printf("QR code count and timestamp logged to file.\n");
    }

    return 0;
}

bool check_valid_qr_code(char qr_code[])
{
    int i;
    if (strlen(qr_code) != QR_CODE_SIZE-1)
    {
        return false;
    }
    for (i=0; i<strlen(qr_code); i++)
    {
        if (!isdigit(qr_code[i]))
        {
            return false;
        }
    }
    return true;
}

void decode_qr_code(char qr_code[], char result[])
{
    int i;
    for (i=0; i<QR_CODE_SIZE-1; i++)
    {
        result[i] = qr_code[i] + 1;
    }
    result[QR_CODE_SIZE-1] = '\0';
}

void log_qr_code(char qr_code[])
{
    FILE *fptr;
    time_t current_time;
    char timestamp[50];
    char log_msg[MAX_FILE_SIZE];

    time(&current_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    sprintf(log_msg, "QR code scanned: %s\tTimestamp: %s", qr_code, timestamp);

    fptr = fopen("log.txt", "a");
    if (fptr == NULL)
    {
        printf("Error: Could not open log file.\n");
    }
    else
    {
        fprintf(fptr, "%s\n", log_msg);
        fclose(fptr);
    }
}