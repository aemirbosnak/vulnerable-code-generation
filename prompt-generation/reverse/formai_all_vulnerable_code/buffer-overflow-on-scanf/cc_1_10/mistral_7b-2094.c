//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
/* Dennis Ritchie Style Sorter */

#define MAX_SIZE 100

typedef struct {
    int value;
    char name[20];
} Data;

void swap(Data *a, Data *b) {
    Data temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(Data arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s : %d\n", arr[i].name, arr[i].value);
    }
}

int partition(Data arr[], int low, int high) {
    int pivot = arr[high].value;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(Data arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    Data data[MAX_SIZE];
    int i, n;

    printf("Enter number of elements : ");
    scanf("%d", &n);

    printf("\nEnter %d data elements:\n", n);

    for (i = 0; i < n; i++) {
        printf("\nName %d : ", i + 1);
        scanf("%s", data[i].name);
        printf("Value : ");
        scanf("%d", &data[i].value);
    }

    quick_sort(data, 0, n - 1);

    printf("\nSorted data:\n");
    print_array(data, n);

    return 0;
}