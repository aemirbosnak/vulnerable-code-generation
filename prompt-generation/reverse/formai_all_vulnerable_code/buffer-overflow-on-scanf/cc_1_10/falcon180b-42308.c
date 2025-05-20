//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, correct = 0, wrong = 0, total = 0;
    char sentence[100], input[100];
    float speed, accuracy;
    struct tm *t;
    time_t now;

    srand(time(NULL));

    printf("Welcome to the Romantic Typing Speed Test!\n");
    printf("Get ready to type some love quotes and messages!\n");

    while (1) {
        printf("\n");
        printf("Press 1 to start the test\n");
        printf("Press 2 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            now = time(NULL);
            t = localtime(&now);
            printf("\n");
            printf("The current time is: %s", asctime(t));

            for (int i = 0; i < 5; i++) {
                printf("\n");
                printf("Type the following sentence as fast and accurately as possible:\n");
                printf("Sentence %d: ", i + 1);
                fflush(stdin);
                fgets(sentence, 100, stdin);
                total += strlen(sentence);

                printf("You typed: %s\n", input);
                if (strcmp(sentence, input) == 0) {
                    correct++;
                } else {
                    wrong++;
                }
            }

            speed = (float)total / 5;
            accuracy = (float)correct / 5 * 100;

            printf("\n");
            printf("Your typing speed is %.2f words per minute.\n", speed);
            printf("Your typing accuracy is %.2f%%.\n", accuracy);

            break;
        } else if (choice == 2) {
            printf("Thank you for using the Romantic Typing Speed Test!\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}