//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
//Time and date libraries are added

#define capacity 50
typedef struct {
    int passt_ID;
    char lug_size;
    int lug_weight;
    long int tag_ID;
} Luggage; 

Luggage arr[capacity];

int main() 
{ 
    printf("Welcome to the Baggage Handling Simulation!\n");

    int n, c, i;

    //Use of Random time function
    srand(time(NULL)); 

    printf("Enter number of passengers needing baggage handling services.\n"); 
    scanf("%d", &n);

    printf("Enter number of luggage per passenger.\n"); 
    scanf("%d", &c);

    printf("Processing...\n");
    for (i = 0; i < n*c; i++) 
    { 
        arr[i].passt_ID = i+1; 

        if (rand() % 2 == 0)
            arr[i].lug_size = 'L'; 
        else
            arr[i].lug_size = 'S'; 

        arr[i].lug_weight = (rand() % 20) + 1; 

        arr[i].tag_ID = 1000000 + rand() % 9000000; 
    }

    //Use of Bubble Sort algorithm to sort the luggage based on weight
    int j; 
    Luggage temp; 
    for(i = 0; i < n*c-1; i++) 
    { 
        for(j = 0; j < n*c-i-1; j++) 
        { 
            if(arr[j].lug_weight > arr[j+1].lug_weight) 
            { 
                temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            } 
        } 
    }

    // Comical conversation between the luggage
    printf("\n\nLuggage Romeo:");
    for (i = 0; i < n*c; i++)
    {
        printf("\n");
        printf("%c%d weighing %d kg. Will you be my tag ID %ld?", arr[i].lug_size, arr[i].passt_ID, arr[i].lug_weight, arr[i].tag_ID);
        printf("\nLuggage Juliet:\n");
        printf("I'm sorry, my heart belongs to another.");
    }
    printf("\n\nSimulation complete. Have a nice flight!\n");
    return 0;
}