//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_SIZE 20

void* convertDate(void* arg);

int main() {
    pthread_t tid;
    char input[MAX_INPUT_SIZE];

    printf("Enter a date in the format (DD-MM-YYYY): ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    int* date = malloc(sizeof(int) * 3);
    if (date == NULL) {
        printf("Error: Memory allocation failed");
        return 1;
    }

    int count = sscanf(input, "%d-%d-%d", &date[0], &date[1], &date[2]);
    if (count != 3) {
        printf("Error: Invalid input format");
        return 1;
    }

    printf("Converting the date...\n");

    int ret = pthread_create(&tid, NULL, convertDate, date);
    if (ret != 0) {
        printf("Error: pthread_create failed");
        return 1;
    }

    ret = pthread_join(tid, NULL);
    if (ret != 0) {
        printf("Error: pthread_join failed");
        return 1;
    }

    free(date);
    return 0;
}

void* convertDate(void* arg) {
    int* date = (int*) arg;

    struct tm time = {0};
    time.tm_mday = date[0];
    time.tm_mon = date[1] - 1;
    time.tm_year = date[2] - 1900;

    time_t timeSinceEpoch = mktime(&time);
    if (timeSinceEpoch == -1) {
        printf("Error: Failed to convert the date\n");
        pthread_exit(NULL);
    }

    char buffer[30];
    strftime(buffer, 30, "%A, %d %B %Y", localtime(&timeSinceEpoch));
    printf("%s\n", buffer);

    pthread_exit(NULL);
}