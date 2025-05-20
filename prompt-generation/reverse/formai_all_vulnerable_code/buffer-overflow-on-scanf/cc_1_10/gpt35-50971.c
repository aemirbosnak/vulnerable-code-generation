//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Alan Touring
#include<stdio.h>

// Define the circuit elements
struct circuit_elements{
    char type[20];
    float value;
    char name[20];
    int node1,node2;
} element[20];

int number_of_elements; // To keep track of number of elements in the circuit

// Function to read the circuit elements from the user
void read_circuit(){
    printf("Enter the number of circuit elements : ");
    scanf("%d",&number_of_elements);
    for(int i=0;i<number_of_elements;i++){
        printf("--------------------------\n");
        printf("Enter details of element %d\n",(i+1));
        printf("--------------------------\n");
        printf("Enter the element type : ");
        scanf("%s",element[i].type);
        printf("Enter the element value : ");
        scanf("%f",&element[i].value);
        printf("Enter the element name : ");
        scanf("%s",element[i].name);
        printf("Enter the node1 : ");
        scanf("%d",&element[i].node1);
        printf("Enter the node2 : ");
        scanf("%d",&element[i].node2);
    }
}

// Function to display the circuit elements
void display_circuit(){
    printf("-------------------------------------------------------------------------\n");
    printf("\t\t\t\tCIRCUIT\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Type\t\tValue\t\tName\t\tNode1\t\tNode2\n");
    printf("-------------------------------------------------------------------------\n");
    for(int i=0;i<number_of_elements;i++){
        printf("%s\t\t%f\t%s\t\t%d\t\t%d\n",element[i].type,element[i].value,element[i].name,element[i].node1,element[i].node2);
    }
    printf("-------------------------------------------------------------------------\n");
}

int main(){
    printf("Welcome to Alan Touring's Classical Circuit Simulator\n");
    printf("----------------------------------------------------\n\n");
    read_circuit();
    display_circuit();
    return 0;
}