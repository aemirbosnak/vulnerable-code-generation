//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include<stdio.h>
#include<math.h>

int main(){

    int n,g=1;
    printf("Enter the number of gates: ");
    scanf("%d",&n);

    // Initializing arrays for inputs and outputs
    int a[n][2],y[n];

    // Taking inputs from the user
    for(int i=0;i<n;i++){
        printf("Enter the inputs for Gate %d: ",i+1);
        scanf("%d%d",&a[i][0],&a[i][1]);
    }

    // Calculating outputs for the given inputs
    for(int i=0;i<n;i++){
        int x1=a[i][0],x2=a[i][1];
        switch(i+1){
            case 1: y[i]=x1&x2;break;
            case 2: y[i]=x1|x2;break;
            case 3: y[i]=x1^x2;break;
            case 4: y[i]=!(x1&x2);break;
            case 5: y[i]=!(x1|x2);break;
            case 6: y[i]=!(x1^x2);break;
        }
    }

    // Printing the outputs
    printf("\nTruth Table for the given gates:\n");
    printf(" ------------\n");
    printf("| a1 | a2 | y |\n");
    printf("|----|----|---|\n");
    for(int i=0;i<n;i++){
        printf("| %d  | %d  | %d |\n",a[i][0],a[i][1],y[i]);
        printf("|----|----|---|\n");
    }

    // Finding maximum gate delay
    int delay[6]={5,4,7,8,6,3},max=0;
    for(int i=0;i<n;i++){
        if(y[i]==1){
            if(max<delay[i]) max=delay[i];
        }
    }

    // Printing the result after calculating maximum delay
    printf("\nMaximum delay for the given gates: %d ns\n",max*100);

    return 0;
}