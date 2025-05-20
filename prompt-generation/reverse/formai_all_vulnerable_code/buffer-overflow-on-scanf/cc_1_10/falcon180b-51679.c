//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUM_FORTUNES 100
#define MAX_LEN_FORTUNE 80

typedef struct {
    char text[MAX_LEN_FORTUNE];
    int length;
} fortune;

fortune fortunes[MAX_NUM_FORTUNES];
int num_fortunes = 0;

void add_fortune(char* new_fortune) {
    if (num_fortunes >= MAX_NUM_FORTUNES) {
        printf("Error: Too many fortunes.\n");
        return;
    }

    strncpy(fortunes[num_fortunes].text, new_fortune, MAX_LEN_FORTUNE);
    fortunes[num_fortunes].length = strlen(new_fortune);

    num_fortunes++;
}

void print_fortune(int index) {
    printf("%s\n", fortunes[index].text);
}

int main() {
    srand(time(NULL));

    add_fortune("You will meet a tall, dark stranger.");
    add_fortune("A financial opportunity is coming your way.");
    add_fortune("Beware of a friend who is not what they seem.");

    int choice;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter 1 to get a random fortune or 2 to add your own:\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int index = rand() % num_fortunes;
        print_fortune(index);
    } else if (choice == 2) {
        char input[MAX_LEN_FORTUNE];
        printf("Enter your fortune:\n");
        scanf("%s", input);
        add_fortune(input);
        printf("Your fortune has been added.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}