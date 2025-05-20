//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
typedef long process;
process now, list;
char command;
int flag;
struct {
	process next;
	int stat;
}procq[100];
int nprocq;
main()
{
	procq[1].next = 0;
	nprocq = 1;
	for (;;) {
		printf("Command (c=create,d=delete,r=run,n=next)?\n");
		command = getchar();
		command = toupper(command);
		printf("Process number (0-99)?\n");
		scanf("%ld", &now);
		switch (command) {
			case 'C':
				insert(now, 0);
				printf("Process %d created, initial state 0\n", now);
				break;
			case 'D':
				delete(now);
				printf("Process %d deleted\n", now);
				break;
			case 'R':
				run(now);
				printf("Process %d set to running\n", now);
				break;
			case 'N':
				next(now);
				printf("Next process is %d\n", now);
				break;
			default:
				printf("Invalid command\n");
		}
	}
}
insert(process p, int i)
{
	while (procq[nprocq].next != 0) nprocq++;
	procq[nprocq].next = p;
	procq[p].stat = i;
}
delete(process p)
{
	while (nprocq > 1 || procq[nprocq].next != p) nprocq--;
	procq[nprocq].next = 0;
}
run(process p)
{
	while (procq[nprocq].next != p) nprocq--;
	procq[p].stat = 1;
}
next(process p)
{
	if (procq[nprocq].next == 0) {
		now = 0;
	} else {
		nprocq = 1;
		while (procq[nprocq].next != p) nprocq++;
		if (procq[procq[nprocq].next].stat <= 0) now = procq[procq[nprocq].next].next;
		else next(procq[nprocq].next);
	}
}