//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 100

// Structure to hold fortunes
typedef struct {
    char text[100];
    char category[50];
} fortune;

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to read fortunes from a file
void read_fortunes(char* filename, fortune fortunes[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", fortunes[count].text, fortunes[count].category)!= EOF) {
        count++;
        if (count >= MAX_FORTUNES) {
            printf("Error: Too many fortunes in file %s\n", filename);
            exit(1);
        }
    }

    fclose(file);
}

// Function to print a fortune
void print_fortune(fortune fortune) {
    printf("%s (%s)\n", fortune.text, fortune.category);
}

// Function to choose a random fortune from an array
void choose_fortune(fortune fortunes[], int num_fortunes) {
    int index = rand_int(0, num_fortunes - 1);
    print_fortune(fortunes[index]);
}

int main() {
    srand(time(0));

    fortune fortunes[MAX_FORTUNES];

    // Read fortunes from file
    read_fortunes("fortunes.txt", fortunes);

    // Choose a random fortune
    choose_fortune(fortunes, MAX_FORTUNES);

    return 0;
}