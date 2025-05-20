//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ELEMENTS 118

struct element {
    char name[3];
    char symbol[3];
    int atomic_number;
    int atomic_weight;
};

void *quiz_thread(void *arg);

int main() {
    pthread_t threads[NUM_ELEMENTS];
    struct element elements[NUM_ELEMENTS];

    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s %s %d %d", elements[i].name, elements[i].symbol, &elements[i].atomic_number, &elements[i].atomic_weight);
        i++;
    }

    fclose(fp);

    for (i = 0; i < NUM_ELEMENTS; i++) {
        pthread_create(&threads[i], NULL, quiz_thread, (void *)&elements[i]);
    }

    for (i = 0; i < NUM_ELEMENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *quiz_thread(void *arg) {
    struct element element = *((struct element *) arg);

    printf("What is the symbol for element %d? ", element.atomic_number);
    scanf("%s", element.symbol);

    if (strcmp(element.symbol, element.name) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct symbol is %s.\n", element.name);
    }

    return NULL;
}