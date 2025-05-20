//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY 100
#define MAX_NAMES 50

// Function to generate a random name
char *generate_name() {
    static char names[MAX_NAMES][20] = {"John", "Jane", "Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Grace", "Harry", "Iris", "Jack", "Kate", "Leo", "Mary", "Nina", "Oliver", "Peter", "Quinn", "Rose", "Sam", "Tina", "Uma", "Victor", "Wendy", "Xander", "Yara", "Zach"};
    return names[rand() % MAX_NAMES];
}

// Function to generate a random conspiracy theory
void generate_theory(int num_conspirators, int complexity) {
    int i;
    char *names[MAX_CONSPIRACY];
    for (i = 0; i < num_conspirators; i++) {
        names[i] = generate_name();
    }
    printf("The %s conspiracy involves %d people:\n", generate_name(), num_conspirators);
    for (i = 0; i < num_conspirators; i++) {
        printf("%s\n", names[i]);
    }
    switch (complexity) {
        case 1:
            printf("Their goal is to control the world's supply of %s.\n", generate_name());
            break;
        case 2:
            printf("They are working together to create a new world order based on the principles of %s.\n", generate_name());
            break;
        case 3:
            printf("The %s conspiracy is actually a front for an even more sinister plot involving %s.\n", generate_name(), generate_name());
            break;
        default:
            printf("The true nature of the %s conspiracy remains shrouded in mystery...\n", generate_name());
            break;
    }
}

int main() {
    srand(time(NULL));
    int num_conspirators, complexity;
    printf("Enter the number of conspirators (1-10): ");
    scanf("%d", &num_conspirators);
    printf("Enter the complexity level (1-3): ");
    scanf("%d", &complexity);
    generate_theory(num_conspirators, complexity);
    return 0;
}