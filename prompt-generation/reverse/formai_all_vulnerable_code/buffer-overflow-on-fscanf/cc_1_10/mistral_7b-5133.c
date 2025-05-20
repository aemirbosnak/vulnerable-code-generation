//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_FORTUNES 10

// Struct to hold a fortune
typedef struct {
    char* description;
    int lucky_number;
} Fortune;

// Function to generate a random number between min and max (inclusive)
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to read a fortune from a file and return it as a Fortune struct
Fortune read_fortune(FILE* file) {
    char description[256];
    char* end;
    int lucky_number;

    fgets(description, sizeof(description), file); // Read fortune description
    description[strcspn(description, "\n")] = '\0'; // Remove newline character

    fscanf(file, "%d", &lucky_number); // Read lucky number

    Fortune fortune = {.description = strdup(description), .lucky_number = lucky_number};

    return fortune;
}

// Function to print a fortune
void print_fortune(const Fortune* fortune) {
    printf("\nYour fortune: %s\n", fortune->description);
    printf("Your lucky number: %d\n", fortune->lucky_number);
}

int main() {
    srand(time(NULL)); // Seed random number generator

    FILE* fortunes_file = fopen("fortunes.txt", "r");
    if (fortunes_file == NULL) {
        perror("Error opening fortunes file");
        exit(1);
    }

    Fortune fortunes[NUM_FORTUNES];
    for (int i = 0; i < NUM_FORTUNES; ++i) {
        fortunes[i] = read_fortune(fortunes_file);
    }
    fclose(fortunes_file);

    int user_choice = random_number(0, NUM_FORTUNES - 1);
    print_fortune(&fortunes[user_choice]);

    for (int i = 0; i < NUM_FORTUNES; ++i) {
        free(fortunes[i].description);
    }

    return 0;
}