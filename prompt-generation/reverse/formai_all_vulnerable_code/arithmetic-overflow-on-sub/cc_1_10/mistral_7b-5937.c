//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define ROWS 5
#define COLS 10
#define PASSWORD_LENGTH 10

typedef struct {
    char character;
    int correct;
} cell;

void generate_password(cell password[ROWS][COLS]);
void print_matrix(cell matrix[ROWS][COLS]);
int is_password_correct(char user_input[PASSWORD_LENGTH], cell password[ROWS][COLS]);
void clear_screen();
int main() {
    srand(time(NULL));
    cell password[ROWS][COLS];
    generate_password(password);
    int total_time = 0;
    int num_correct = 0;
    int num_incorrect = 0;
    char user_input[PASSWORD_LENGTH];
    clock_t start, end;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Your task is to type the following password as fast and accurately as possible:\n");
    print_matrix(password);

    start = clock();
    while (num_correct < PASSWORD_LENGTH) {
        fflush(stdin);
        scanf("%c", &user_input[0]);
        user_input[PASSWORD_LENGTH] = '\0';
        if (is_password_correct(user_input, password)) {
            num_correct++;
            printf("Correct: %c\n", user_input[0]);
        } else {
            num_incorrect++;
            printf("Incorrect: %c\n", user_input[0]);
        }
    }

    end = clock();
    total_time = (int)((end - start) * 1000 / CLOCKS_PER_SEC);
    clear_screen();

    printf("Congratulations, you have typed the password correctly!\n");
    printf("Your typing speed is: %d characters per second\n", (PASSWORD_LENGTH * 1000) / total_time);
    printf("Number of correct characters: %d\n", num_correct);
    printf("Number of incorrect characters: %d\n", num_incorrect);

    return 0;
}

void generate_password(cell password[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            password[i][j].character = rand() % 26 + 'a';
            password[i][j].correct = 0;
        }
    }
}

void print_matrix(cell matrix[ROWS][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", matrix[i][j].character);
        }
        printf("\n");
    }
}

int is_password_correct(char user_input[PASSWORD_LENGTH], cell password[ROWS][COLS]) {
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        if (tolower(user_input[i]) != password[i / COLS][i % COLS].character) {
            return 0;
        }
        password[i / COLS][i % COLS].correct = 1;
    }
    return 1;
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J");
#endif
}