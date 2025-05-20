//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 100
#define MAX_VALUES 100

int main(int argc, char *argv[]) {
    int num_coins, num_values;
    int values[MAX_VALUES];
    int coins[MAX_COINS];
    int i, j, k, max_value, curr_value, curr_coin;

    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    printf("Enter the number of values: ");
    scanf("%d", &num_values);

    //initialize coins and values arrays
    for(i=0; i<num_coins; i++){
        coins[i] = rand()%MAX_VALUES;
    }
    
    for(j=0; j<num_values; j++){
        values[j] = rand()%MAX_VALUES;
    }

    //sort coins array in descending order
    for(i=0; i<num_coins; i++){
        for(j=i+1; j<num_coins; j++){
            if(coins[i] < coins[j]){
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    //initialize max_value and curr_value
    max_value = values[0];
    curr_value = 0;

    //initialize curr_coin to the first coin
    curr_coin = 0;

    //find the maximum value that can be obtained
    for(i=0; i<num_values; i++){
        curr_value += values[i];
        for(j=curr_coin; j<num_coins; j++){
            if(coins[j] <= curr_value){
                curr_value += coins[j];
                curr_coin = j+1;
            }
        }
    }

    printf("The maximum value that can be obtained is: %d\n", max_value);

    return 0;
}