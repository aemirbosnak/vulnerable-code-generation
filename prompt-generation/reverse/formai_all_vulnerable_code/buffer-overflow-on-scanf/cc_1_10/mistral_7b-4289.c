//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#define MAX_KNIGHTS 10

typedef struct knight {
    int valor;
    char name[20];
} knight;

void bubble_sort(knight arr[], int n) {
    int i, j, temp_valor;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].valor < arr[j + 1].valor) {
                temp_valor = arr[j].valor;
                arr[j].valor = arr[j + 1].valor;
                arr[j + 1].valor = temp_valor;

                // Swap knight names
                char temp_name[20];
                strcpy(temp_name, arr[j].name);
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j + 1].name, temp_name);
            }
        }
    }
}

int main() {
    knight knight_array[MAX_KNIGHTS];

    printf("Welcome to the Medieval Valor Sorting!\n");
    printf("Please enter %d knights' names and valor:\n", MAX_KNIGHTS);

    for (int i = 0; i < MAX_KNIGHTS; i++) {
        printf("\nKnight %d:\n", i + 1);
        scanf("%s", knight_array[i].name);
        scanf("%d", &knight_array[i].valor);
    }

    printf("\nBefore sorting:\n");
    for (int i = 0; i < MAX_KNIGHTS; i++) {
        printf("\nName: %s, Valor: %d\n", knight_array[i].name, knight_array[i].valor);
    }

    bubble_sort(knight_array, MAX_KNIGHTS);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < MAX_KNIGHTS; i++) {
        printf("\nName: %s, Valor: %d\n", knight_array[i].name, knight_array[i].valor);
    }

    return 0;
}