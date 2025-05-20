//LLAMA2-13B DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

struct Dream {
    char *name;
    int age;
    float weight;
    double height;
    char *profession;
    int num_dreams;
};

void add_dream(struct Dream *dream, char *name, int age, float weight, double height, char *profession) {
    dream->name = name;
    dream->age = age;
    dream->weight = weight;
    dream->height = height;
    dream->profession = profession;
    dream->num_dreams++;
}

void print_dreams(struct Dream *dreams, int num_dreams) {
    for (int i = 0; i < num_dreams; i++) {
        printf("%s %d %f %lf %s\n", dreams[i].name, dreams[i].age, dreams[i].weight, dreams[i].height, dreams[i].profession);
    }
}

int main() {
    srand(time(NULL));

    struct Dream dreams[10];

    for (int i = 0; i < 10; i++) {
        char *name = "Dream";
        int age = rand() % 100;
        float weight = rand() % 100;
        double height = rand() % 100;
        char *profession = "Surrealist";

        add_dream(&dreams[i], name, age, weight, height, profession);
    }

    print_dreams(dreams, 10);

    return 0;
}