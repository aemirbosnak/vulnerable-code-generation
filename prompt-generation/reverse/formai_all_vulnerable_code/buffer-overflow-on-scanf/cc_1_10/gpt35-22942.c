//FormAI DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct process {
    int id;
    int memory_req;
    char name[50];
    struct process* next;
};

struct memory_block {
    int id;
    int size;
    int occupied;
    struct process* process;
    struct memory_block* next;
};

struct process* create_process(int id, int memory_req, char name[]) {
    struct process* new_process = (struct process*)malloc(sizeof(struct process));
    new_process->id = id;
    new_process->memory_req = memory_req;
    strcpy(new_process->name, name);
    new_process->next = NULL;
    return new_process;
}

struct memory_block* create_memory_block(int id, int size) {
    struct memory_block* new_block = (struct memory_block*)malloc(sizeof(struct memory_block));
    new_block->id = id;
    new_block->size = size;
    new_block->occupied = 0;
    new_block->process = NULL;
    new_block->next = NULL;
    return new_block;
}

void add_free_block(struct memory_block** free_list, struct memory_block* new_block) {
    if (*free_list == NULL) {
        *free_list = new_block;
    } else {
        struct memory_block* current = *free_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_block;
    }
}

void add_process_to_block(struct memory_block* block, struct process* new_process) {
    block->occupied = 1;
    block->process = new_process;
}

void remove_free_block(struct memory_block** free_list, struct memory_block* target_block) {
    if (*free_list == target_block) {
        *free_list = target_block->next;
    } else {
        struct memory_block* current = *free_list;
        while (current->next != target_block) {
            current = current->next;
        }
        current->next = target_block->next;
    }
    target_block->next = NULL;
}

struct memory_block* find_best_fit(struct memory_block* free_list, int memory_req) {
    struct memory_block* current = free_list;
    struct memory_block* best_fit = NULL;
    while (current != NULL) {
        if (current->size >= memory_req) {
            if (best_fit == NULL || current->size < best_fit->size) {
                best_fit = current;
            }
        }
        current = current->next;
    }
    return best_fit;
}

void print_free_blocks(struct memory_block* free_list) {
    struct memory_block* current = free_list;
    while (current != NULL) {
        printf("Free block %d, size %d\n", current->id, current->size);
        current = current->next;
    }
}

void print_memory_map(struct memory_block* memory_map) {
    struct memory_block* current = memory_map;
    while (current != NULL) {
        if (current->occupied) {
            printf("Block %d, size %d, process %s (id %d)\n", current->id, current->size, current->process->name, current->process->id);
        } else {
            printf("Block %d, size %d, free\n", current->id, current->size);
        }
        current = current->next;
    }
}

int main() {
    printf("Welcome to the Memory Manager!\n");
    int memory_size;
    printf("Enter the total memory available: ");
    scanf("%d", &memory_size);

    int option = 0;
    struct process* first_process = NULL;
    struct memory_block* first_block = create_memory_block(1, memory_size);
    struct memory_block* free_list = first_block;
    struct memory_block* memory_map = first_block;

    while (option != 4) {
        printf("\n1. Add process\n");
        printf("2. Remove process\n");
        printf("3. Print memory map\n");
        printf("4. Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nAdding a new process...\n");
                int memory_req;
                char process_name[50];
                printf("Enter process name: ");
                scanf("%s", process_name);
                printf("Enter memory requirement: ");
                scanf("%d", &memory_req);

                struct process* new_process = create_process(1, memory_req, process_name);
                struct memory_block* best_fit = find_best_fit(free_list, memory_req);

                if (best_fit != NULL) {
                    printf("Found best fit block with size %d\n", best_fit->size);
                    add_process_to_block(best_fit, new_process);
                    remove_free_block(&free_list, best_fit);
                } else {
                    printf("No suitable free blocks, adding to end of memory map\n");
                    struct memory_block* new_block = create_memory_block(memory_map->id + 1, memory_req);
                    add_process_to_block(new_block, new_process);
                    memory_map->next = new_block;
                    memory_map = new_block;
                }

                printf("Process %s added to memory\n", new_process->name);
                break;

            case 2:
                printf("\nRemoving an existing process...\n");
                int process_id;
                printf("Enter process id: ");
                scanf("%d", &process_id);

                struct memory_block* current = first_block;
                while (current != NULL && current->process->id != process_id) {
                    current = current->next;
                }

                if (current != NULL) {
                    printf("Deallocating memory of process %s (id %d)\n", current->process->name, current->process->id);
                    add_free_block(&free_list, current);
                    current->occupied = 0;
                    current->process = NULL;
                } else {
                    printf("Process with id %d not found\n", process_id);
                }
                break;

            case 3:
                printf("\nMemory Map:\n");
                print_memory_map(first_block);
                printf("\nFree Blocks:\n");
                print_free_blocks(free_list);
                break;

            case 4:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid option, please try again\n");
                break;
        }
    }

    return 0;
}