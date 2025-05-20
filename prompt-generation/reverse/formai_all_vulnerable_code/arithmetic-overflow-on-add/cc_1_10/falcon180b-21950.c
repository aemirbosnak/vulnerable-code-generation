//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_THREADS 4
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    double value;
} ConversionRequest;

void *convert(void *arg) {
    ConversionRequest *request = arg;
    char *endptr;

    if (strcmp(request->command, "c2f") == 0) {
        request->value = (request->value * 9.0 / 5.0) + 32.0;
    } else if (strcmp(request->command, "f2c") == 0) {
        request->value = (request->value - 32.0) * 5.0 / 9.0;
    } else if (strcmp(request->command, "c2k") == 0) {
        request->value = request->value + 273.15;
    } else if (strcmp(request->command, "k2c") == 0) {
        request->value = request->value - 273.15;
    } else {
        printf("Invalid conversion request: %s\n", request->command);
        exit(1);
    }

    printf("Conversion complete: %s = %.2f\n", request->command, request->value);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    char input[MAX_COMMAND_LENGTH];

    printf("Enter conversion requests in the format 'command value'\n");
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        ConversionRequest request;
        strcpy(request.command, input);
        sscanf(input, "%s %lf", request.command, &request.value);

        pthread_create(&threads[i], NULL, convert, &request);
        i++;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}