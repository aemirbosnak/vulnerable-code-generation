//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h> 
#include <stdlib.h> 
#define MAX 50 

struct baggage 
{ 
    int bagID; 
    char source[MAX];
    char destination[MAX]; 
    int weight; 
}; 

void addBaggage(struct baggage *bag, int n) 
{ 
    for(int i=0;i<n;i++) 
    { 
        fflush(stdin); 
        printf("\nEnter the Baggage ID: "); 
        scanf("%d",&(bag+i)->bagID); 
        fflush(stdin); 
        printf("\nEnter the source of Baggage: "); 
        gets((bag+i)->source); 
        fflush(stdin); 
        printf("Enter the destination of Baggage: ");
        gets((bag+i)->destination); 
        fflush(stdin); 
        printf("Enter the weight of Baggage: "); 
        scanf("%d",&(bag+i)->weight); 
    } 
} 

void displayBaggage(struct baggage *bag, int n) 
{ 
    printf("\nBaggage details entered: "); 
    for(int i=0;i<n;i++) 
    { 
        printf("\nBaggage ID: %d\t", (bag+i)->bagID); 
        printf("Source: %s\t", (bag+i)->source); 
        printf("Destination: %s\t",(bag+i)->destination); 
        printf("Weight: %d\t",(bag+i)->weight); 
    } 
} 

void sortBaggage(struct baggage *bag, int n) 
{ 
    for(int i=0;i<n-1;i++) 
    { 
        for(int j=i+1;j<n;j++) 
        { 
            if(((bag+i)->weight) > ((bag+j)->weight)) 
            { 
                //swap content of struct 
                struct baggage temp = *(bag+i); 
                *(bag+i) = *(bag+j); 
                *(bag+j) = temp; 
            } 
        } 
    } 
} 

int main() 
{ 
    struct baggage * bag; 
    int n; 
    printf("\nEnter no of Baggage: "); 
    scanf("%d", &n); 
    bag = (struct baggage *) malloc(n * sizeof(struct baggage)); 
     
    addBaggage(bag, n); 
    displayBaggage(bag, n); 
    sortBaggage(bag, n); 
    printf("\nBaggage details sorted by weight:\n"); 
    displayBaggage(bag,n); 
    free(bag); 
    return 0; 
}