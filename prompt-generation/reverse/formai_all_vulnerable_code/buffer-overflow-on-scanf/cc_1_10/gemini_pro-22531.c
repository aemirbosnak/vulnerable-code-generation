//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include <stdio.h>

typedef enum { false, true } bool;

struct stack {
    int data;
    struct stack* next;
};

struct tower {
    struct stack* disks;
    int disk_count;
};

void push(struct stack** top, int data) {
    struct stack* new_stack = (struct stack*)malloc(sizeof(struct stack));
    new_stack->data = data;
    new_stack->next = *top;
    *top = new_stack;
}

int pop(struct stack** top) {
    if (*top == NULL) {
        return -1;
    }
    int data = (*top)->data;
    struct stack* next = (*top)->next;
    free(*top);
    *top = next;
    return data;
}

void print_tower(struct tower* tower) {
    struct stack* current = tower->disks;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool move_disk(struct tower* from, struct tower* to, int disk_size) {
    if (from->disk_count == 0) {
        return false;
    }
    if (to->disk_count == 0) {
        push(&to->disks, pop(&from->disks));
        from->disk_count--;
        to->disk_count++;
        return true;
    }
    if (from->disks->data < to->disks->data) {
        push(&to->disks, pop(&from->disks));
        from->disk_count--;
        to->disk_count++;
        return true;
    }
    return false;
}

void solve_tower_of_hanoi(struct tower* towers, int disk_size, int from, int to, int via) {
    if (disk_size == 1) {
        move_disk(&towers[from], &towers[to], disk_size);
        return;
    }
    solve_tower_of_hanoi(towers, disk_size - 1, from, via, to);
    move_disk(&towers[from], &towers[to], disk_size);
    solve_tower_of_hanoi(towers, disk_size - 1, via, to, from);
}

int main() {
    int disk_size;
    printf("Enter the number of disks: ");
    scanf("%d", &disk_size);

    struct tower towers[3];
    for (int i = 0; i < 3; i++) {
        towers[i].disks = NULL;
        towers[i].disk_count = 0;
    }

    for (int i = disk_size; i > 0; i--) {
        push(&towers[0].disks, i);
        towers[0].disk_count++;
    }

    solve_tower_of_hanoi(towers, disk_size, 0, 2, 1);

    for (int i = 0; i < 3; i++) {
        print_tower(&towers[i]);
    }

    return 0;
}