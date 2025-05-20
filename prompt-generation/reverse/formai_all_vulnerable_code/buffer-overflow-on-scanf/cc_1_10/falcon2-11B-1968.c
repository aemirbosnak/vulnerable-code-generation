//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

#define MAX 100

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

int is_prime(int n)
{
	if (n <= 1)
		return 0;

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return 0;

	return 1;
}

int main()
{
	int i, n, flag = 0;
	struct node *temp;

	srand(time(0));

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		if (temp == NULL)
			break;

		temp->data = rand() % MAX;

		if (head == NULL)
			head = temp;

		else
		{
			temp->next = head;
			head = temp;
		}
	}

	if (head!= NULL)
		printf("List is : ");
	else
		printf("List is Empty");

	for (temp = head; temp!= NULL; temp = temp->next)
		printf("%d ", temp->data);

	printf("\n");

	printf("Enter the element to be searched: ");
	scanf("%d", &n);

	temp = head;

	while (temp!= NULL)
	{
		if (temp->data == n)
		{
			printf("Element found at index %d\n", flag);
			flag = 1;
			break;
		}

		temp = temp->next;
	}

	if (flag == 0)
		printf("Element not found\n");

	return 0;
}