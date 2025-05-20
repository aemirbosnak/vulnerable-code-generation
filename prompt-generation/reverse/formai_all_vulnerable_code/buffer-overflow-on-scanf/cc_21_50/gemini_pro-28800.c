//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int t1[n], t2[n], t3[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &t1[i]);
    }

    int m;
    scanf("%d", &m);
    int t4[m], t5[m], t6[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &t4[i]);
    }

    int k;
    scanf("%d", &k);
    int t7[k], t8[k], t9[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &t7[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (t1[i] > t1[j]) {
                int tmp = t1[i];
                t1[i] = t1[j];
                t1[j] = tmp;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (t4[i] > t4[j]) {
                int tmp = t4[i];
                t4[i] = t4[j];
                t4[j] = tmp;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (t7[i] > t7[j]) {
                int tmp = t7[i];
                t7[i] = t7[j];
                t7[j] = tmp;
            }
        }
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++) {
        if (t1[i] == t4[i] && t4[i] == t7[i]) {
            cnt1++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (t1[i] == t4[i]) {
            cnt2++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (t1[i] == t7[i]) {
            cnt3++;
        }
    }

    if (cnt1 == n) {
        printf("Equal\n");
    } else if (cnt2 == n || cnt3 == n) {
        printf("Similar\n");
    } else {
        printf("Different\n");
    }

    return 0;
}