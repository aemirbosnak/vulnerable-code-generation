//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int res_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < res_time);
}

void clear_screen() {
    system("cls || clear");
}

int main() {
    int count = 0;
    double start_time, end_time, total_time;
    char input;
    clear_screen();
    printf("Welcome to the Typing Speed Test program!\n\n");
    printf("You will be given a series of random characters to type. Press enter after each character.\n\n");
    printf("When you are ready to start, press enter.\n\n");
    getchar();
    clear_screen();
    while (1) {
        srand(time(NULL));
        char random_char = 'a' + (rand() % 26);
        printf("%c ", random_char);
        start_time = clock();
        input = getchar();
        end_time = clock();
        if (input == random_char) {
            total_time += (end_time - start_time) / CLOCKS_PER_SEC;
            count++;
            if (count == 50) {
                break;
            }
        }
        else {
            printf("\n\nIncorrect input. Game Over!");
            getchar();
            return 0;
        }
        delay(1);
        clear_screen();
    }
    printf("\n\nCongratulations! You have completed the test!\n");
    printf("Total typing time: %.2fs \n", total_time);
    printf("Typing speed: %.2f characters per second\n", count / total_time);
    printf("Press enter to exit the program.");
    getchar();
    return 0;
}