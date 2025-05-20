//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num_bags, num_flights, num_carriers, i, j, k;
    float avg_weight;
    char bag_type[20], carrier_type[20];
    int bag_id[10], flight_id[10], carrier_id[10];
    float bag_weight[10];
    
    printf("Enter number of bags: ");
    scanf("%d", &num_bags);
    
    for(i=0; i<num_bags; i++){
        printf("Enter bag type: ");
        scanf("%s", &bag_type);
        
        printf("Enter bag ID: ");
        scanf("%d", &bag_id[i]);
        
        printf("Enter bag weight: ");
        scanf("%f", &bag_weight[i]);
    }
    
    printf("Enter number of flights: ");
    scanf("%d", &num_flights);
    
    for(i=0; i<num_flights; i++){
        printf("Enter flight ID: ");
        scanf("%d", &flight_id[i]);
        
        printf("Enter carrier type: ");
        scanf("%s", &carrier_type);
        
        printf("Enter carrier ID: ");
        scanf("%d", &carrier_id[i]);
    }
    
    for(i=0; i<num_bags; i++){
        for(j=0; j<num_flights; j++){
            if(bag_type[i] == carrier_type[j]){
                k = flight_id[j];
                break;
            }
        }
        
        if(k!= -1){
            printf("Bag %d is on flight %d with carrier %s.\n", bag_id[i], k, carrier_type[j]);
        }
    }
    
    printf("Average weight of bags: %.2f\n", avg_weight = 0.0);
    
    for(i=0; i<num_bags; i++){
        avg_weight += bag_weight[i];
    }
    
    avg_weight /= num_bags;
    
    printf("Average weight of bags: %.2f\n", avg_weight);
}