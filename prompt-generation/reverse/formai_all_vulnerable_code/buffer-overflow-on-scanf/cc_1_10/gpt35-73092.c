//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 3

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int display_instruction() {
    int option;

    printf("Welcome to Typing Speed Test!\n");
    printf("Instructions:\n");
    printf("1. In each test, you will be given a set of random words to type.\n");
    printf("2. Type the words as quickly and accurately as possible.\n");
    printf("3. Press enter to move on to the next word.\n");
    printf("4. At the end of the test, your typing speed will be displayed.\n");
    printf("5. Ready to begin?\n");
    printf("6. Press 1 to start or 0 to exit.\n");

    do {
        printf("\nPosition: ");
        scanf("%d", &option);
        clear_input_buffer();
        if (option != 1 && option != 0) {
            printf("Invalid option. Try again.\n");
        }
    } while (option != 1 && option != 0);
    
    return option;
}

double calculate_typing_speed(double seconds, int num_words) {
    return num_words / seconds * 60;
}

void run_typing_test(char** words, int num_words) {
    int i, j;
    clock_t start, end;
    char input[50];
    double typing_time, speed;

    printf("Test starting in 3 seconds...\n");
    sleep(3);
    printf("Begin!\n");

    start = clock();
    for (i = 0; i < num_words; i++) {
        printf("> %s ", words[i]);
        fgets(input, sizeof(input), stdin);
        for(j=0; j<=sizeof(input); j++) {
            if(input[j] == '\n') {
                input[j] = '\0';
            }
        }
    }
    end = clock();

    typing_time = (double)(end - start) / CLOCKS_PER_SEC;
    speed = calculate_typing_speed(typing_time, num_words);
    printf("Your typing speed is %.2f words per minute.\n", speed);
}

char** generate_random_words(int num_words) {
    int i, j, word_len;
    const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    char** words = (char**)malloc(num_words * sizeof(char*));

    srand(time(NULL));

    for (i = 0; i < num_words; i++) {
        word_len = rand() % 10 + 1;
        words[i] = (char*)malloc((word_len + 1) * sizeof(char));
        for (j = 0; j < word_len; j++) {
            words[i][j] = alphabet[rand() % 26];
        }
        words[i][word_len] = '\0';
    }

    return words;
}

void free_words(char** words, int num_words) {
    int i;
    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
}


int main() {
    int option, i;
    char** words;

    option = display_instruction();

    if (option == 1) {
        for (i = 1; i <= NUM_TESTS; i++) {
            printf("Test %d starting.\n", i);
            words = generate_random_words(20);
            run_typing_test(words, 20);
            free_words(words, 20);
        }
        printf("All tests complete.\n");
    } else {
        printf("Exiting...\n");
    }

    return 0;
}