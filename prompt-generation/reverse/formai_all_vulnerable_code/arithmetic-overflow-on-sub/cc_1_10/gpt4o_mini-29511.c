//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_KNIGHTS 100

typedef struct {
    char name[50];
    int valor; // valor represents the courage or bravery of the knight
} Knight;

void swap(Knight* a, Knight* b) {
    Knight temp = *a;
    *a = *b;
    *b = temp;
}

void sortKnights(Knight knights[], int count) {
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (knights[j].valor < knights[j + 1].valor) {
                swap(&knights[j], &knights[j + 1]);
            }
        }
    }
}

void printKnights(Knight knights[], int count) {
    printf("List of Brave Knights:\n");
    printf("-------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s with Valor: %d\n", knights[i].name, knights[i].valor);
    }
    printf("-------------------------\n");
}

int main() {
    Knight knights[MAX_KNIGHTS];
    int count = 0;
    
    printf("Enter the number of knights (Max %d): ", MAX_KNIGHTS);
    scanf("%d", &count);

    if (count > MAX_KNIGHTS) {
        printf("Alas! Too many knights, the maximum is %d.\n", MAX_KNIGHTS);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter the name of Knight %d: ", i + 1);
        scanf("%s", knights[i].name);
        printf("Enter the valor (bravery level) of %s: ", knights[i].name);
        scanf("%d", &knights[i].valor);
    }

    printf("\nBefore the Sorting Tournament:\n");
    printKnights(knights, count);

    sortKnights(knights, count);

    printf("\nAfter the Sorting Tournament:\n");
    printKnights(knights, count);

    return 0;
}