//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct tower
{
	int *disks;
	int num_disks;
	int max_disks;
} tower;

tower *create_tower(int num_disks)
{
	tower *t = (tower *)malloc(sizeof(tower));
	t->disks = (int *)malloc(sizeof(int) * num_disks);
	t->num_disks = num_disks;
	t->max_disks = num_disks;

	for (int i = 0; i < num_disks; i++)
	{
		t->disks[i] = num_disks - i;
	}

	return t;
}

void destroy_tower(tower *t)
{
	free(t->disks);
	free(t);
}

void move_disk(tower *t, int from, int to)
{
	int disk = t->disks[from];

	if (disk == 0)
	{
		printf("Invalid move: cannot move the base disk.\n");
	}
	else if (from == to)
	{
		printf("Invalid move: cannot move a disk to the same tower.\n");
	}
	else
	{
		t->disks[from] = t->disks[to];
		t->disks[to] = disk;
	}
}

void print_tower(tower *t)
{
	for (int i = 0; i < t->num_disks; i++)
	{
		printf("%d", t->disks[i]);
	}

	printf("\n");
}

int main(void)
{
	int num_disks;

	printf("Enter the number of disks: ");
	scanf("%d", &num_disks);

	tower *t = create_tower(num_disks);

	print_tower(t);

	move_disk(t, 0, 1);
	move_disk(t, 0, 2);
	move_disk(t, 1, 2);
	move_disk(t, 0, 1);
	move_disk(t, 2, 0);
	move_disk(t, 2, 1);
	move_disk(t, 0, 2);

	print_tower(t);

	destroy_tower(t);

	return 0;
}