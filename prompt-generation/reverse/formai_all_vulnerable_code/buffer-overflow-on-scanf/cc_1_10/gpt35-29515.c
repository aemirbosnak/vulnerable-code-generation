//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include<stdio.h>

//defining a function to calculate the maximum number of activities
void activitySelection(int start[], int finish[], int n){
    int i, j;
    printf("Selected Activities: ");
    
    //always select the first activity
    i = 0;
    printf("%d ", i+1);
    
    //for the rest of the activities
    for(j=1;j<n;j++){
        //if the start time of the current activity is greater than or equal to the finish time of the previous selected activity
        if(start[j]>=finish[i]){
            printf("%d ", j+1);
            i=j; //update the index of previously selected activity to the current activity
        }
    }
}

int main(){
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    int start[n], finish[n];
    printf("Enter the start and finish time of activities: \n");
    for(int i=0;i<n;i++){
        printf("Activity %d: ", i+1);
        scanf("%d %d", &start[i], &finish[i]);
    }
    
    //sorting the activities according to their finish time using bubble sort
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(finish[j] > finish[j+1]){
                int temp = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = temp;
                
                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    activitySelection(start, finish, n);
    
    return 0;
}