//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>

#define MAX_SECTIONS 10
#define MAX_BINS_PER_SECTION 20

typedef unsigned char bit_t;

struct section_t {
    bit_t bins[MAX_BINS_PER_SECTION];
};

int count_sections(struct section_t* section) {
    int count = 0;
    while (section->bins[count]!= 0) {
        count++;
    }
    return count;
}

int count_items_in_section(struct section_t* section, int section_index) {
    int count = 0;
    for (int i = 0; i < MAX_BINS_PER_SECTION; i++) {
        if (section->bins[i]!= 0) {
            count++;
        }
    }
    return count;
}

int count_items_in_bin(struct section_t* section, int section_index, int bin_index) {
    int count = 0;
    if (section->bins[bin_index]!= 0) {
        count++;
    }
    return count;
}

void print_inventory(struct section_t* sections[MAX_SECTIONS]) {
    int section_index = 0;
    int bin_index = 0;
    int item_count = 0;

    printf("Inventory:\n");
    while (section_index < MAX_SECTIONS) {
        int section_count = count_sections(sections[section_index]);
        printf("Section %d: %d items\n", section_index, section_count);
        while (bin_index < MAX_BINS_PER_SECTION) {
            int section_item_count = count_items_in_section(sections, section_index);
            int bin_item_count = count_items_in_bin(sections, section_index, bin_index);
            printf("Bin %d: %d items\n", bin_index, bin_item_count);
            item_count += section_item_count + bin_item_count;
            bin_index++;
        }
        section_index++;
        bin_index = 0;
    }
    printf("Total items: %d\n", item_count);
}

int main() {
    struct section_t sections[MAX_SECTIONS];

    printf("Enter the number of sections:\n");
    int section_count;
    scanf("%d", &section_count);

    printf("Enter the number of bins per section:\n");
    int bin_count;
    scanf("%d", &bin_count);

    for (int i = 0; i < section_count; i++) {
        for (int j = 0; j < bin_count; j++) {
            int item_count;
            scanf("%d", &item_count);
            sections[i].bins[j] = item_count;
        }
    }

    print_inventory(sections);

    return 0;
}