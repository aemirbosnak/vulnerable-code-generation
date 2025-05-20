//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int correct_count = 0, wrong_count = 0, total_count = 0;
    char input_string[100];
    char *correct_string;
    int length;

    printf("Welcome to the typing speed test!\n");
    printf("Please type the following sentence:\n");
    printf("The quick brown fox jumps over the lazy dog.\n");

    fflush(stdout);
    system("clear"); // clear console

    time_t start_time, end_time;
    start_time = time(NULL);

    while (1) {
        if (feof(stdin)) {
            end_time = time(NULL);
            total_count = (int) (end_time - start_time);
            break;
        }

        fgets(input_string, 100, stdin);
        length = strlen(input_string);

        if (length == 0) {
            continue;
        }

        correct_string = strstr(input_string, "The quick brown fox jumps over the lazy dog.");
        if (correct_string!= NULL) {
            correct_count++;
        } else {
            wrong_count++;
        }

        total_count++;
    }

    printf("Congratulations! You have completed the typing speed test!\n");
    printf("Correct characters: %d\n", correct_count);
    printf("Wrong characters: %d\n", wrong_count);
    printf("Total characters: %d\n", total_count);
    printf("Accuracy: %.2f%%\n", (float) correct_count / total_count * 100);

    return 0;
}