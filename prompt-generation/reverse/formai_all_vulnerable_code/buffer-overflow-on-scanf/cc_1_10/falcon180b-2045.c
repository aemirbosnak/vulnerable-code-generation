//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_FORTUNES 50
#define MAX_FORTUNE_LENGTH 80

struct fortune {
    char text[MAX_FORTUNE_LENGTH];
    bool is_lucky;
};

static struct fortune fortunes[MAX_FORTUNES];
static int num_fortunes;

void generate_fortunes() {
    srand(time(NULL));

    fortunes[num_fortunes++] = (struct fortune) {
       .text = "The early bird gets the worm. ",
       .is_lucky = true,
    };

    fortunes[num_fortunes++] = (struct fortune) {
       .text = "A penny saved is a penny earned. ",
       .is_lucky = false,
    };

    fortunes[num_fortunes++] = (struct fortune) {
       .text = "You can't make an omelette without breaking eggs. ",
       .is_lucky = true,
    };

    fortunes[num_fortunes++] = (struct fortune) {
       .text = "Actions speak louder than words. ",
       .is_lucky = false,
    };

    fortunes[num_fortunes++] = (struct fortune) {
       .text = "A watched pot never boils. ",
       .is_lucky = true,
    };
}

void print_fortune(int index) {
    if (index < 0 || index >= num_fortunes) {
        printf("Invalid fortune index.\n");
        return;
    }

    struct fortune fortune = fortunes[index];
    printf("%s\n", fortune.text);
}

int main() {
    generate_fortunes();

    int choice;
    do {
        printf("Enter your choice (0-9): ");
        scanf("%d", &choice);

        if (choice >= 0 && choice < num_fortunes) {
            print_fortune(choice);
        } else {
            printf("Invalid choice.\n");
        }
    } while (true);

    return 0;
}