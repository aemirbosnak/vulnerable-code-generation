//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int result;
    int recursive_flag;
} recursive_data;

void recursive_factorial(int num, recursive_data *data) {
    if (num == 0) {
        data->result = 1;
        data->recursive_flag = 0;
        return;
    }

    if (data->recursive_flag == 1) {
        printf("Error: Recursive call already in progress!\n");
        exit(1);
    }

    data->recursive_flag = 1;
    recursive_data *new_data = (recursive_data *) malloc(sizeof(recursive_data));
    new_data->num = num - 1;
    new_data->result = 0;
    new_data->recursive_flag = 0;

    recursive_factorial(num - 1, new_data);

    data->result *= new_data->result;
    free(new_data);
    data->recursive_flag = 0;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    recursive_data data;
    data.num = num;
    data.result = 1;
    data.recursive_flag = 0;

    recursive_factorial(num, &data);

    printf("Factorial of %d is %d\n", num, data.result);

    return 0;
}