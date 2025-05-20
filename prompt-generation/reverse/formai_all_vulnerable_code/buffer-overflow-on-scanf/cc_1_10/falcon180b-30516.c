//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STR_LEN 100
#define NUM_FORTUNES 10

typedef struct {
    char text[MAX_STR_LEN];
    int is_good_fortune;
} Fortune;

Fortune fortunes[NUM_FORTUNES] = {
    {"You will find true love soon.", 1},
    {"Financial success is in your future.", 1},
    {"Beware of false friends.", 0},
    {"A new opportunity will present itself to you.", 1},
    {"You will experience a small setback, but it will lead to greater success.", 1},
    {"Your hard work will pay off soon.", 1},
    {"You will receive good news from a friend.", 1},
    {"You will have a lucky day today.", 1},
    {"You will overcome a difficult challenge.", 1},
    {"You will make a positive change in your life.", 1}
};

void shuffle_array(int arr[], int n) {
    int i, j, temp;
    srand(time(0));
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void display_fortune(Fortune fortune) {
    printf("%s %s\n", fortune.text, fortune.is_good_fortune? " (Good fortune)" : " (Bad fortune)");
}

int main() {
    char choice;
    int num_fortunes;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("I will use my advanced algorithms to predict your future.\n");
    printf("How many fortunes would you like to receive? ");
    scanf("%d", &num_fortunes);

    if (num_fortunes > NUM_FORTUNES || num_fortunes <= 0) {
        printf("Sorry, I can only provide up to %d fortunes at a time.\n", NUM_FORTUNES);
        return 1;
    }

    printf("Shuffling fortunes...\n");
    shuffle_array(fortunes, NUM_FORTUNES);

    for (int i = 0; i < num_fortunes; i++) {
        printf("Your %dth fortune:\n", i+1);
        display_fortune(fortunes[i]);
    }

    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}