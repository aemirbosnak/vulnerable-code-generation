//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

struct baggage{
    int id;
    int destination;
    int status;
};

void createBaggage(struct baggage *baggage, int num){
    int i;
    for(i=0; i<num; i++){
        baggage[i].id = i+1;
        baggage[i].destination = rand()%3+1;
        baggage[i].status = 0;
    }
}

void displayBaggage(struct baggage *baggage, int num){
    int i;
    for(i=0; i<num; i++){
        printf("Baggage %d is destined for location %d and its status is %d\n", baggage[i].id, baggage[i].destination, baggage[i].status);
    }
}

void sortBaggage(struct baggage *baggage, int num){
    int i, j, temp;
    for(i=0; i<num-1; i++){
        for(j=i+1; j<num; j++){
            if(baggage[i].destination > baggage[j].destination){
                temp = baggage[i].id;
                baggage[i].id = baggage[j].id;
                baggage[j].id = temp;
            }
        }
    }
}

void moveBaggage(struct baggage *baggage, int num){
    int i;
    for(i=0; i<num; i++){
        if(baggage[i].status == 0){
            baggage[i].status = 1;
        }
    }
}

int main(){
    int num;
    printf("Enter the number of baggage: ");
    scanf("%d", &num);

    struct baggage baggage[num];
    createBaggage(baggage, num);
    displayBaggage(baggage, num);
    sortBaggage(baggage, num);
    moveBaggage(baggage, num);

    return 0;
}