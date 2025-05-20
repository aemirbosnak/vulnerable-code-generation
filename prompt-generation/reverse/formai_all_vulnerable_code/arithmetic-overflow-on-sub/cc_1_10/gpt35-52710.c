//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main() {
    clear();
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a passage to type out as quickly and accurately as possible.\n");
    printf("Press any key to start.\n");
    getchar();

    const char passage[] = {"The quick brown fox jumps over the lazy dog."};
    const int passage_len = sizeof(passage)/sizeof(char) - 1;
    char user_input[passage_len];
    int i, errors = 0;
    double time_taken;

    printf("Type the following passage: \n%s\n\n", passage);

    clock_t start_time = clock();
    fgets(user_input, passage_len, stdin);
    clock_t end_time = clock();

    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    for(i = 0; i < passage_len; i++) {
        if(user_input[i] != passage[i]) {
            errors++;
        }
    }

    printf("\nYou took %.2f seconds to type the passage.\n", time_taken);
    printf("You made %d errors.\n", errors);

    if(errors == 0) {
        printf("Congratulations! You typed the passage perfectly!\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}