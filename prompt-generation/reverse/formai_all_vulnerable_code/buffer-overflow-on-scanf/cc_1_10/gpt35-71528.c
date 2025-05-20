//FormAI DATASET v1.0 Category: Memory management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Memory Management Program!\n");
    printf("In this surreal world, bytes are replaced with fruits,\n");
    printf("and the computer tries to eat them all.\n");

    int mem_size;
    printf("How many fruits would you like to allocate for the computer?\n");
    scanf("%d", &mem_size);

    printf("\nThe computer has been given %d fruits!\n", mem_size);

    srand(time(NULL));
    char* fruits = malloc(mem_size * sizeof(char));
    if(fruits == NULL) {
        printf("The computer is allergic to fruits. Memory allocation failed.\n");
        return 1;
    }

    printf("\nThe computer is happily eating fruits!\n");
    for(int i = 0; i < mem_size; i++) {
        fruits[i] = (rand() % 26) + 'a'; // generate a random lowercase letter
        printf("Computer ate a %c.\n", fruits[i]);
    }

    printf("\nUh-oh, the computer has overeaten and is starting to feel sick.\n");
    free(fruits); // return the allocated memory to the OS

    printf("\nBut the surreal world doesn't end here!\n");
    printf("Instead of deallocating memory, the fruits have now turned into flowers!\n");

    int flower_size;
    printf("\nHow many flowers would you like to allocate for the computer's recovery?\n");
    scanf("%d", &flower_size);

    printf("\nThe computer has been given %d flowers!\n", flower_size);

    srand(time(NULL));
    char* flowers = malloc(flower_size * sizeof(char));
    if(flowers == NULL) {
        printf("The computer is still allergic to flowers. Memory allocation failed.\n");
        return 1;
    }

    printf("\nThe computer is now surrounded by beautiful flowers!\n");
    for(int i = 0; i < flower_size; i++) {
        flowers[i] = (rand() % 26) + 'A'; // generate a random uppercase letter
        printf("Computer smells a %c.\n", flowers[i]);
    }

    printf("\nThe computer has fully recovered by smelling the beautiful flowers!\n");
    free(flowers); // return the allocated memory to the OS

    printf("Goodbye from the surreal world of Memory Management!\n");

    return 0;
}