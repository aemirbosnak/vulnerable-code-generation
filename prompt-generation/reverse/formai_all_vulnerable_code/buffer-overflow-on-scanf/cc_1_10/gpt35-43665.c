//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate array of random numbers between 1 to 100
int* generate_random_array(int n) {
    int* arr = (int*)malloc(n*sizeof(int));
    srand(time(0));
    for(int i=0; i<n; i++) {
        arr[i] = rand()%100+1;
    }
    return arr;
}

// Function to print the array elements
void print_array(int* arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to implement Greedy technique to select clothes
void select_clothes(int* arr, int n) {
    int total_cost = 0;
    int days = 0;
    for(int i=0; i<n; i++) {
        if(arr[i]<20 && days%7<5) {
            // Wear T-Shirt on weekdays if the cost is less than 20
            total_cost += arr[i];
            days++;
            printf("Wearing T-Shirt on day %d\n", days);
        }
        else if(arr[i]>=20 && arr[i]<50) {
            // Wear polo T-Shirt on weekends if the cost is between 20 and 50
            if(days%7>=5) {
                total_cost += arr[i];
                days++;
                printf("Wearing Polo T-Shirt on day %d\n", days);
            }
        }
        else if(arr[i]>=50 && days%7==0) {
            // Wear buttoned shirt on Mondays if the cost is greater than 50
            total_cost += arr[i];
            days++;
            printf("Wearing Buttoned Shirt on Monday %d\n", days/7);
        }
    }
    printf("Total cost of clothes worn: %d\n", total_cost);
}

int main() {
    int n;
    printf("How many clothes do you have in your wardrobe?\n");
    scanf("%d", &n);
    int* arr = generate_random_array(n);
    printf("Your wardrobe collection:\n");
    print_array(arr, n);
    printf("Let's select the clothes based on greedy algorithm...\n\n");
    select_clothes(arr, n);
    return 0;
}