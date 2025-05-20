//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100
#define MAX_NUM 1000

typedef struct {
    char name[MAX_SIZE];
    int num;
    int index;
} person;

void init(person* arr, int size) {
    for(int i = 0; i < size; i++) {
        arr[i].index = -1;
        arr[i].num = 0;
    }
}

int cmp(const void* a, const void* b) {
    person* p1 = (person*)a;
    person* p2 = (person*)b;
    if(p1->num > p2->num) {
        return 1;
    } else if(p1->num < p2->num) {
        return -1;
    } else {
        return 0;
    }
}

void swap(person* arr, int i, int j) {
    person temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    person arr[n];
    init(arr, n);
    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i].name);
        if(i == 0) {
            arr[i].num = 0;
        } else {
            for(int j = 0; j < i; j++) {
                int d = 0;
                for(int k = 0; k < strlen(arr[j].name); k++) {
                    if(arr[j].name[k]!= arr[i].name[k]) {
                        d = 1;
                        break;
                    }
                }
                if(d == 0) {
                    arr[i].num = arr[j].num + 1;
                    break;
                }
            }
        }
    }
    qsort(arr, n, sizeof(person), cmp);
    for(int i = 0; i < n; i++) {
        printf("%s %d\n", arr[i].name, arr[i].num);
    }
    return 0;
}