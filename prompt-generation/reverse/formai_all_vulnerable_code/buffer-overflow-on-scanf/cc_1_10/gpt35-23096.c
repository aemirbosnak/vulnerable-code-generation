//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fortune_teller(void* arg);

int main(int argc, char *argv[]) {
    pthread_t tid;
    int status;
    char *message = "Welcome to Automated Fortune Teller!";

    // Create new thread
    if ((status = pthread_create(&tid, NULL, fortune_teller, (void*)message)) != 0) {
        printf("Error creating thread: %d\n", status);
        exit(EXIT_FAILURE);
    }

    // Wait for thread to finish
    if ((status = pthread_join(tid, NULL)) != 0) {
        printf("Error joining thread: %d\n", status);
        exit(EXIT_FAILURE);
    }

    printf("\nThank you for using Automated Fortune Teller. Goodbye!\n");

    return 0;
}

void *fortune_teller(void* arg) {
    char *message = (char*) arg;
    char question[200];

    printf("%s\n", message);

    while (1) {
        printf("\nPlease enter your question (or enter 'quit' to exit): ");
        scanf("%s", question);

        if (strcmp(question, "quit") == 0) {
            break;
        }

        // Generate random fortune message
        int num = rand() % 5 + 1;
        char *fortune;

        switch (num) {
            case 1:
                fortune = "It is certain.";
                break;
            case 2:
                fortune = "Ask again later.";
                break;
            case 3:
                fortune = "Outlook not so good.";
                break;
            case 4:
                fortune = "You may rely on it.";
                break;
            case 5:
                fortune = "Reply hazy, try again.";
                break;
            default:
                fortune = "Error: invalid fortune number.";
        }

        printf("The fortune teller says: %s\n", fortune);
    }

    pthread_exit(NULL);
}