//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_FIB_NUM 100

int fibonacci[MAX_FIB_NUM];

void generate_fibonacci() {
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i = 2; i < MAX_FIB_NUM; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
}

void print_fibonacci(int x, int y, int num) {
    for(int i = 0; i < num; i++) {
        printf("%d ", fibonacci[i]);
    }
}

void draw_fibonacci() {
    system("clear");
    printf("Fibonacci Sequence Visualizer\n");
    printf("Press any key to generate a new sequence\n");
    getchar();
    generate_fibonacci();
    int start_x = (WIDTH - 12) / 2;
    int start_y = (HEIGHT - 3) / 2;
    print_fibonacci(start_x, start_y, MAX_FIB_NUM);
}

int main() {
    srand(time(NULL));
    int choice = rand() % 2;
    if(choice == 0) {
        draw_fibonacci();
    } else {
        system("clear");
        printf("Fibonacci Sequence Visualizer\n");
        printf("Press any key to generate a new sequence\n");
        getchar();
        generate_fibonacci();
        int start_x = (WIDTH - 12) / 2;
        int start_y = (HEIGHT - 3) / 2;
        print_fibonacci(start_x, start_y, MAX_FIB_NUM);
    }
    return 0;
}