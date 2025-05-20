//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include<stdio.h> 
#include<string.h> 
#define MAX_LEN 100

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int calcLevenshteinDistance(char string1[],char string2[],int length1,int length2) 
{
    int distanceArray[MAX_LEN][MAX_LEN];
    int i,j,cost;

    for(i=0;i<=length1;i++) {
        distanceArray[i][0] = i;
    }

    for(j=0;j<=length2;j++) {
        distanceArray[0][j] = j;
    }

    for(i=1;i<=length1;i++) {
        for(j=1;j<=length2;j++) {
            cost = (string1[i-1] == string2[j-1]) ? 0 : 1;
            distanceArray[i][j] = minimum(distanceArray[i-1][j]+1,
                                        distanceArray[i][j-1]+1,
                                        distanceArray[i-1][j-1]+cost);
        }
    }

    return distanceArray[length1][length2];
}

int main() {
    char string1[MAX_LEN],string2[MAX_LEN];
    int distance;

    printf("Enter the first string: ");
    scanf("%s",string1);

    printf("Enter the second string: ");
    scanf("%s",string2);

    int length1 = strlen(string1);
    int length2 = strlen(string2);

    distance = calcLevenshteinDistance(string1,string2,length1,length2);

    printf("Levenshtein distance between %s and %s is %d.\n",string1,string2,distance);

    return 0;
}