//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASCII_LOW 97
#define ASCII_UP 65
#define ALPHABET_SIZE 26

void print_letter(int letter) {
    putchar(letter + ASCII_LOW);
}

void print_word(char* word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        print_letter(word[i]);
        if (i < (strlen(word) - 1))
            putchar(' ');
    }
}

int get_random_number(int max) {
    int number, random_seed;
    clock_t start_time, current_time;

    random_seed = time(NULL);
    start_time = clock();

    while ((current_time = clock()) - start_time < CLOCKS_PER_SEC) {
        number = (rand() % max);
    }

    return number;
}

int main() {
    int month, fortune;
    char* fortunes[12];

    srand(time(NULL));

    fortunes[0] = "You will find a treasure.";
    fortunes[1] = "You will make a new friend.";
    fortunes[2] = "You will have a lucky day.";
    fortunes[3] = "You will have good news.";
    fortunes[4] = "You will have a bad day.";
    fortunes[5] = "You will meet someone interesting.";
    fortunes[6] = "You will have a peaceful day.";
    fortunes[7] = "You will have a productive day.";
    fortunes[8] = "You will have a romantic day.";
    fortunes[9] = "You will have a successful day.";
    fortunes[10] = "You will have a creative day.";
    fortunes[11] = "You will have an adventurous day.";

    printf("Enter your birth month (1-12): ");
    scanf("%d", &month);

    month--; // Adjust for 0-indexed array

    fortune = get_random_number(strlen(fortunes[month]));

    printf("Your fortune: ");
    print_word(fortunes[month]);
    putchar(' ');

    print_letter((fortune + 1) % ALPHABET_SIZE + ASCII_UP);
    putchar('.');

    return 0;
}