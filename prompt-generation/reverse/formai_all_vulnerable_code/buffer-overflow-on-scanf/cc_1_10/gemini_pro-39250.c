//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOVE_FORWARD "前进"
#define MOVE_BACKWARD "后退"
#define MOVE_LEFT "向左"
#define MOVE_RIGHT "向右"
#define TAKE_OFF "起飞"
#define LAND "降落"
#define HOVER "悬停"
#define SPIN_LEFT "向左旋转"
#define SPIN_RIGHT "向右旋转"
#define FLIP_FORWARD "向前翻滚"
#define FLIP_BACKWARD "向后翻滚"
#define FLIP_LEFT "向左翻滚"
#define FLIP_RIGHT "向右翻滚"

typedef struct {
    char *name;
    void (*function)(void);
} command;

void move_forward(void) {
    printf("无人机正在前进！\n");
}

void move_backward(void) {
    printf("无人机正在后退！\n");
}

void move_left(void) {
    printf("无人机正在向左移动！\n");
}

void move_right(void) {
    printf("无人机正在向右移动！\n");
}

void take_off(void) {
    printf("无人机正在起飞！\n");
}

void land(void) {
    printf("无人机正在降落！\n");
}

void hover(void) {
    printf("无人机正在悬停！\n");
}

void spin_left(void) {
    printf("无人机正在向左旋转！\n");
}

void spin_right(void) {
    printf("无人机正在向右旋转！\n");
}

void flip_forward(void) {
    printf("无人机正在向前翻滚！\n");
}

void flip_backward(void) {
    printf("无人机正在向后翻滚！\n");
}

void flip_left(void) {
    printf("无人机正在向左翻滚！\n");
}

void flip_right(void) {
    printf("无人机正在向右翻滚！\n");
}

int main(void) {
    char input[100];
    command commands[] = {
        {MOVE_FORWARD, move_forward},
        {MOVE_BACKWARD, move_backward},
        {MOVE_LEFT, move_left},
        {MOVE_RIGHT, move_right},
        {TAKE_OFF, take_off},
        {LAND, land},
        {HOVER, hover},
        {SPIN_LEFT, spin_left},
        {SPIN_RIGHT, spin_right},
        {FLIP_FORWARD, flip_forward},
        {FLIP_BACKWARD, flip_backward},
        {FLIP_LEFT, flip_left},
        {FLIP_RIGHT, flip_right},
    };

    printf("欢迎使用无人机遥控器！\n");
    printf("请输入您要执行的命令：\n");
    while (1) {
        scanf("%s", input);
        for (int i = 0; i < sizeof(commands) / sizeof(command); i++) {
            if (strcmp(input, commands[i].name) == 0) {
                commands[i].function();
                break;
            }
        }
    }

    return 0;
}