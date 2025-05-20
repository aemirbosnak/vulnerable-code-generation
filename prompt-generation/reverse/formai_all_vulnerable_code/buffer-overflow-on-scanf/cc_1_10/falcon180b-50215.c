//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to shuffle an array
void shuffle(char* arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand_int(0, n - 1);
        char* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Function to print the fortune
void print_fortune(char* fortune, char* name) {
    printf("Your fortune, %s:\n%s\n", name, fortune);
}

// Function to generate a random fortune
char* generate_fortune() {
    char* fortunes[] = {
        "You will find true love soon.",
        "A new opportunity is coming your way.",
        "Your hard work will pay off.",
        "You will experience a great adventure.",
        "You will receive good news today.",
        "You will overcome a challenge.",
        "You will have a lucky day.",
        "You will make a new friend.",
        "You will achieve your goals.",
        "You will have a prosperous future."
    };
    return fortunes[rand_int(0, sizeof(fortunes) / sizeof(fortunes[0]) - 1)];
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char* name;
    printf("What is your name? ");
    scanf("%s", name);

    char* fortune = generate_fortune();
    print_fortune(fortune, name);

    return 0;
}