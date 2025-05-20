//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int age;
    float wealth;
} Knight;

void read_knight_data(FILE *fp, Knight *knight) {
    fscanf(fp, "%s %d %f", knight->name, &knight->age, &knight->wealth);
}

void display_knight_data(Knight knight) {
    printf("%s, a noble knight, %d years old, with a wealth of %.2f gold coins.\n", knight.name, knight.age, knight.wealth);
}

int main() {
    FILE *data_file;
    Knight *knights, knight;
    int num_knights;

    data_file = fopen("knight_data.txt", "r");
    if (data_file == NULL) {
        printf("Error: Unable to open knight data file.\n");
        return 1;
    }

    fscanf(data_file, "%d", &num_knights);
    knights = (Knight *) calloc(num_knights, sizeof(Knight));

    for (int i = 0; i < num_knights; i++) {
        read_knight_data(data_file, &knights[i]);
    }

    printf("\nThe data of our noble knights:\n");
    for (int i = 0; i < num_knights; i++) {
        display_knight_data(knights[i]);
    }

    free(knights);
    fclose(data_file);

    return 0;
}

/* The contents of the knight_data.txt file:
2
Sir Lancelot 25 1000.5
Sir Gawain 30 1500.0
*/