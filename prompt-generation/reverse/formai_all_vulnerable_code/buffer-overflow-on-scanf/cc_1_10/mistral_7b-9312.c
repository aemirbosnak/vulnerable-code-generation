//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#define MAX_PROC 5
#define TIME_QUANTUM 2
#define CPU_IDLE 0
typedef struct {
 int pid;
 int burst_time;
 int waiting_time;
 int turnaround_time;
} process;
process queue[MAX_PROC], ready[MAX_PROC];
int head = 0, tail = -1;
int rhead = 0, rtail = -1;
int time_slice = 0, counter = 0;
void enqueue(int pid, int bt) {
 if (tail >= MAX_PROC - 1) {
 printf("\nQueue is full\n");
 return;
 }
 queue[++tail] = (process){pid, bt, 0, 0};
}
void dequeue() {
 if (head > tail) {
 printf("\nQueue is empty\n");
 return;
 }
 process p = queue[head++];
}
void add_ready(int pid, int bt) {
 if (rtail >= MAX_PROC - 1) {
 printf("\nReady queue is full\n");
 return;
 }
 ready[++rtail] = (process){pid, bt, 0, 0};
}
void remove_ready() {
 if (rhead > rtail) {
 printf("\nReady queue is empty\n");
 return;
 }
 process p = ready[rhead++];
}
void schedule() {
 process p;
 if (head > tail) {
 p = queue[head++];
 add_ready(p.pid, p.burst_time);
 } else {
 p = ready[rhead++];
 time_slice = p.burst_time < TIME_QUANTUM ? p.burst_time : TIME_QUANTUM;
 p.burst_time -= time_slice;
 p.waiting_time += time_slice;
 counter++;
 if (p.burst_time == 0) {
 p.turnaround_time = p.waiting_time + time_slice;
 printf("\nProcess %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n", p.pid, p.burst_time, p.waiting_time, p.turnaround_time);
 }
 }
 if (counter == MAX_PROC) {
 printf("\nAll processes have been executed\n");
 return;
 }
 time_slice = TIME_QUANTUM;
}
void cpu_idle() {
 printf("\nIDLE: %d\n", ++time_slice);
}
int main() {
 int i, pid, bt;
 for (i = 0; i < 5; i++) {
 printf("\nEnter process %d's burst time: ", i + 1);
 scanf("%d", &bt);
 enqueue(i + 1, bt);
 }
 while (1) {
 if (head > tail)
 schedule();
 else
 cpu_idle();
 }
 return 0;
}