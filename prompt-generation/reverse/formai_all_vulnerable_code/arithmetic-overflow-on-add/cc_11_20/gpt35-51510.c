//FormAI DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char location[50];
} Person;

typedef struct {
    int id;
    char name[50];
    int members_count;
    Person members[100];
} Group;

int main() {
    int choice;
    Group groups[100];
    int groups_count = 0;

    while (1) {
        printf("1. Create Group\n");
        printf("2. Add Member to Group\n");
        printf("3. Remove Member from Group\n");
        printf("4. View Group Members\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Group group;
                group.id = groups_count + 1;
                printf("Enter Group Name: ");
                scanf("%s", group.name);
                group.members_count = 0;

                groups[groups_count] = group;
                groups_count++;

                printf("Group created successfully!\n");
                break;
            }
            case 2: {
                int group_id;
                printf("Enter Group ID: ");
                scanf("%d", &group_id);

                if (group_id <= groups_count) {
                    Person member;
                    member.id = groups[group_id - 1].members_count + 1;

                    printf("Enter Member Name: ");
                    scanf("%s", member.name);

                    printf("Enter Member Age: ");
                    scanf("%d", &member.age);

                    printf("Enter Member Location: ");
                    scanf("%s", member.location);

                    groups[group_id - 1].members[groups[group_id - 1].members_count] = member;
                    groups[group_id - 1].members_count++;

                    printf("Member added successfully!\n");
                } else {
                    printf("Invalid Group ID!\n");
                }
                break;
            }
            case 3: {
                int group_id;
                printf("Enter Group ID: ");
                scanf("%d", &group_id);

                if (group_id <= groups_count) {
                    int member_id;
                    printf("Enter Member ID: ");
                    scanf("%d", &member_id);

                    if (member_id <= groups[group_id - 1].members_count) {
                        for (int i = member_id - 1; i < groups[group_id - 1].members_count; i++) {
                            groups[group_id - 1].members[i] = groups[group_id - 1].members[i + 1];
                        }

                        groups[group_id - 1].members_count--;

                        printf("Member removed successfully!\n");
                    } else {
                        printf("Invalid Member ID!\n");
                    }
                } else {
                    printf("Invalid Group ID!\n");
                }
                break;
            }
            case 4: {
                int group_id;
                printf("Enter Group ID: ");
                scanf("%d", &group_id);

                if (group_id <= groups_count) {
                    Group group = groups[group_id - 1];

                    printf("Group ID: %d\n", group.id);
                    printf("Group Name: %s\n", group.name);
                    printf("Group Members:\n");

                    for (int i = 0; i < group.members_count; i++) {
                        Person member = group.members[i];
                        printf("\tMember ID: %d\n", member.id);
                        printf("\tMember Name: %s\n", member.name);
                        printf("\tMember Age: %d\n", member.age);
                        printf("\tMember Location: %s\n", member.location);
                        printf("\n");
                    }
                } else {
                    printf("Invalid Group ID!\n");
                }
                break;
            }
            case 5: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid Choice!\n");
                break;
            }
        }
    }

    return 0;
}