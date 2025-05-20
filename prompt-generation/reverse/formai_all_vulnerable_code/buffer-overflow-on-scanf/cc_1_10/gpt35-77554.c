//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include<stdio.h>
#include<stdlib.h>

int main(){

int n, i, j, temp, sum=0;

printf("Enter the number of elements: ");
scanf("%d", &n);

int weight[n];
float profitperweight[n], profit=0;

for(i=0;i<n;i++){

printf("Enter the weight and profit for element %d: ", i+1);
scanf("%d", &weight[i]);
scanf("%f", &profitperweight[i]);

}

for(i=0;i<n-1;i++){

for(j=i+1;j<n;j++){

if(profitperweight[i]<profitperweight[j]){

temp=profitperweight[i];
profitperweight[i]=profitperweight[j];
profitperweight[j]=temp;

temp=weight[i];
weight[i]=weight[j];
weight[j]=temp;

}

}

}

int capacity;
float fraction[n];

printf("Enter the capacity of knapsack: ");
scanf("%d", &capacity);

for(i=0;i<n;i++){

if(capacity<weight[i]){
break;
}
else{

fraction[i]=1.0;
capacity=capacity-weight[i];
profit=profit+profitperweight[i];

}

}

if(i<n){

fraction[i]=(float)capacity/weight[i];
profit=profit+fraction[i]*profitperweight[i];

}

printf("The maximum profit that can be obtained is: %.2f\n", profit);

return 0;

}