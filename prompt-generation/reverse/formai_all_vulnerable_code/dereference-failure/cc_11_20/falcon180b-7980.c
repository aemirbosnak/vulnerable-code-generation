//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *name;
    int size;
    int used;
} MemoryBlock;

int main() {
    int i, j, n, m, k;
    char input[50];
    MemoryBlock *memory = (MemoryBlock*)malloc(MAX_SIZE * sizeof(MemoryBlock));

    for (i = 0; i < MAX_SIZE; i++) {
        memory[i].name = (char*)malloc(50 * sizeof(char));
        memory[i].size = 0;
        memory[i].used = 0;
    }

    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of memory block %d: ", i+1);
        scanf("%s", memory[i].name);
        printf("Enter the size of memory block %s: ", memory[i].name);
        scanf("%d", &memory[i].size);
    }

    while (1) {
        system("clear");
        printf("RAM USAGE MONITOR\n");
        printf("-------------------\n");
        for (i = 0; i < n; i++) {
            printf("%-20s %10d %10d\n", memory[i].name, memory[i].size, memory[i].used);
        }
        printf("\n");

        printf("Enter command (a/r/e/q): ");
        scanf("%s", input);

        if (input[0] == 'a') {
            printf("Enter the name of the memory block: ");
            scanf("%s", input);
            for (j = 0; j < n; j++) {
                if (strcmp(memory[j].name, input) == 0) {
                    printf("Enter the new size of %s: ", input);
                    scanf("%d", &m);
                    memory[j].size = m;
                    break;
                }
            }
        }
        else if (input[0] == 'r') {
            printf("Enter the name of the memory block: ");
            scanf("%s", input);
            for (j = 0; j < n; j++) {
                if (strcmp(memory[j].name, input) == 0) {
                    printf("Enter the amount of memory to release (%d-%d): ", memory[j].used, memory[j].size);
                    scanf("%d", &k);
                    memory[j].used -= k;
                    break;
                }
            }
        }
        else if (input[0] == 'e') {
            printf("Exiting program...\n");
            break;
        }
        else if (input[0] == 'q') {
            printf("Quitting program...\n");
            exit(0);
        }
        else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}