//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void print_intro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
}

void print_turn_count(int turn) {
    printf("You are on turn %d.\n", turn);
}

void end_game() {
    printf("Goodbye!\n");
    exit(0);
}

int main() {
    int turn = 1;
    
    while (1) {
        print_intro();
        printf("> ");
        char input[100];
        scanf("%s", input);
        
        if (strcmp(input, "quit") == 0) {
            end_game();
        } else if (strcmp(input, "more") == 0) {
            print_turn_count(turn);
            printf("> ");
            scanf("%s", input);
        } else {
            int number;
            read_number(input, &number);
            if (number == 0) {
                printf("Invalid input.\n");
            } else {
                turn += number;
                print_turn_count(turn);
                printf("> ");
                scanf("%s", input);
            }
        }
    }
    
    return 0;
}

int read_number(char* input, int* number) {
    int value = 0;
    char* endptr;
    
    if (sscanf(input, "%d", &value) == 1) {
        *number = value;
        return 1;
    } else {
        endptr = strchr(input, '\n');
        if (endptr!= NULL) {
            *endptr = '\0';
        }
    }
    
    return 0;
}

void print_number(int number) {
    printf("%d\n", number);
}