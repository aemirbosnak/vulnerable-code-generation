//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>

#define MAX_N 100 // maximum number of intervals

// Structure to hold an interval
typedef struct Interval {
  int start;
  int end;
} Interval;

// Function to compare intervals based on their end time
int compare_intervals(const void* a, const void* b) {
  const Interval* ia = (const Interval*)a;
  const Interval* ib = (const Interval*)b;
  return ia->end - ib->end;
}

// Function to find the maximum number of non-overlapping intervals
int max_non_overlapping_intervals(Interval intervals[], int n) {
  // Sort the intervals based on their end time
  qsort(intervals, n, sizeof(Interval), compare_intervals);

  int count = 1; // number of non-overlapping intervals
  int current_end = intervals[0].end; // end of current interval

  for (int i = 1; i < n; i++) {
    if (intervals[i].start >= current_end) {
      // This interval does not overlap with the current one
      count++;
      current_end = intervals[i].end;
    }
  }

  return count;
}

int main() {
  Interval intervals[MAX_N];
  int n;

  // Read in the intervals
  printf("Enter the number of intervals: ");
  scanf("%d", &n);

  printf("Enter the intervals (start end):\n");
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &intervals[i].start, &intervals[i].end);
  }

  // Find the maximum number of non-overlapping intervals
  int count = max_non_overlapping_intervals(intervals, n);

  printf("The maximum number of non-overlapping intervals is %d\n", count);

  return 0;
}