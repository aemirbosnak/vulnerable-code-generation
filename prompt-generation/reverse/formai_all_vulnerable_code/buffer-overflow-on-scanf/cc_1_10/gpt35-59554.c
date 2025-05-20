//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct circuit{
    int source;
    int dest;
    float resistance;
} Circuit;

Circuit circuit_array[SIZE];
int circuit_size = 0;

void add_circuit(){
    if(circuit_size == SIZE){
        printf("Circuit capacity full\n");
        return;
    }
    printf("Enter source node: ");
    scanf("%d", &circuit_array[circuit_size].source);
    printf("Enter destination node: ");
    scanf("%d", &circuit_array[circuit_size].dest);
    printf("Enter resistance: ");
    scanf("%f", &circuit_array[circuit_size].resistance);
    circuit_size++;
    printf("Circuit added successfully\n");
}

void print_circuits(){
    printf("Source\tDest\tResistance\n");
    for(int i=0; i<circuit_size; i++){
        printf("%d\t%d\t%.2f\n", circuit_array[i].source, circuit_array[i].dest, circuit_array[i].resistance);
    }
}

int main(){
    int choice = 0;
    while(choice != 3){
        printf("1. Add Circuit\n2. Print Circuits\n3. Exit Program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_circuit();
                break;
            case 2:
                print_circuits();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}