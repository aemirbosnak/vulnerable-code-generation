//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

int circuit[MAX];
int n;

void add_element(int value) {
    circuit[n++] = value;
}

void display() {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", circuit[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of elements in the circuit: ");
    scanf("%d", &n);

    printf("Enter the circuit elements:\n");

    int i, value;
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        add_element(value);
    }

    printf("Circuit elements:\n");
    display();

    int flag = 0;
    int x, y, z;

    while(flag == 0) {
        printf("Enter the circuit elements to be connected:\n");
        scanf("%d %d %d", &x, &y, &z);

        if(circuit[x] == circuit[y]) {
            printf("Error! Elements already connected.\n");
        }
        else {
            circuit[x] = circuit[y];
            flag = 1;
        }
    }

    printf("Circuit after connecting elements:\n");
    display();

    return 0;
}