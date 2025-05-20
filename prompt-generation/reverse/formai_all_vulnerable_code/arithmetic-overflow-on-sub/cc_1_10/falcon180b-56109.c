//Falcon-180B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// define a structure for our knights
typedef struct knight_s {
    char name[30];
    int age;
    float height;
} knight_t;

// function prototypes
void create_knights(knight_t knights[], int n);
void print_knights(knight_t knights[], int n);
void sort_by_age(knight_t knights[], int n);
void sort_by_height(knight_t knights[], int n);

int main() {
    int n;

    // ask the user how many knights they want to sort
    printf("Enter the number of knights: ");
    scanf("%d", &n);

    // create an array of knights
    knight_t knights[n];

    // populate the array with random knights
    create_knights(knights, n);

    // print the unsorted list of knights
    printf("\nUnsorted List of Knights:\n");
    print_knights(knights, n);

    // sort the knights by age
    sort_by_age(knights, n);
    printf("\n\nSorted by Age:\n");
    print_knights(knights, n);

    // sort the knights by height
    sort_by_height(knights, n);
    printf("\n\nSorted by Height:\n");
    print_knights(knights, n);

    return 0;
}

// function to create n random knights
void create_knights(knight_t knights[], int n) {
    for (int i = 0; i < n; i++) {
        knights[i].age = rand() % 50 + 18; // knights must be at least 18 years old
        knights[i].height = rand() % 101 + 150; // knights must be at least 150cm tall
        sprintf(knights[i].name, "Sir %d", i + 1); // give each knight a unique name
    }
}

// function to print the list of knights
void print_knights(knight_t knights[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%-30s %d years old, %.2f cm tall\n", knights[i].name, knights[i].age, knights[i].height);
    }
}

// function to sort the knights by age
void sort_by_age(knight_t knights[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (knights[j].age < knights[i].age) {
                // swap knights[i] and knights[j] if knights[j] is younger
                knight_t temp = knights[i];
                knights[i] = knights[j];
                knights[j] = temp;
            }
        }
    }
}

// function to sort the knights by height
void sort_by_height(knight_t knights[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (knights[j].height < knights[i].height) {
                // swap knights[i] and knights[j] if knights[j] is shorter
                knight_t temp = knights[i];
                knights[i] = knights[j];
                knights[j] = temp;
            }
        }
    }
}