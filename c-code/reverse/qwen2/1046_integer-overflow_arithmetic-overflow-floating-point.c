#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define N 1024

void fft(int *x, int n) {
    if (n <= 1) return;
    int even[n/2], odd[n/2];
    for (int i = 0; i < n/2; i++) {
        even[i] = x[2*i];
        odd[i] = x[2*i + 1];
    }
    fft(even, n/2);
    fft(odd, n/2);
    for (int k = 0; k < n/2; k++) {
        int t = even[k];
        even[k] = t + odd[k];
        odd[k] = t - odd[k];
    }
}

int main() {
    int x[N];
    for (int i = 0; i < N; i++) {
        x[i] = rand();
    }
    fft(x, N);
    return 0;
}
