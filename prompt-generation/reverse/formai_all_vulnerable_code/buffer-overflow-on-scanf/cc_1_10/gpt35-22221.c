//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 10000
#define MAX_NUM 1000

int nums[MAX_N];
int freq[MAX_NUM+1];

int main() {
    int n = 0;
    int max_num = 0;
    int min_num = MAX_NUM;
    int mode = 0;
    float mean = 0.0f;
    float median = 0.0f;
    
    // Read input
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
        if(nums[i] > max_num) max_num = nums[i];
        if(nums[i] < min_num) min_num = nums[i];
        freq[nums[i]]++;
    }
    
    // Calculate Mean
    for(int i=0; i<n; i++) {
        mean += (float) nums[i];
    }
    mean /= (float) n;
    
    // Calculate Median
    int mid = n/2;
    if(n % 2 == 0) {
        median = (float) (nums[mid-1] + nums[mid]) / 2.0f;
    } else {
        median = (float) nums[mid];
    }
    
    // Calculate Mode
    for(int i=min_num; i<=max_num; i++) {
        if(freq[i] > freq[mode]) {
            mode = i;
        }
    }
    
    printf("Mean: %f\n", mean);
    printf("Median: %f\n", median);
    printf("Mode: %d\n", mode);
    
    return 0;
}